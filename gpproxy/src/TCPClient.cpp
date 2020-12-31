#include "gpproxy/TCPClient.hpp"

#include <iostream>

using namespace gp::proxy;

stde::log::log TCPClient::l = stde::log::log::get("tcp-client");

TCPClient::TCPClient(ProxyPlayer* player, const std::string& ip, int port) : m_player(player), m_socket(stde::net::sock_address(ip, std::to_string(port))), m_is(
        m_socket), m_os(m_socket), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os, stde::streams::endianconv::big), m_running(
        false) {
}

TCPClient::TCPClient(ProxyPlayer* player, const std::string& ip) : m_player(player), m_socket(stde::net::sock_address(ip)), m_is(
        m_socket), m_os(m_socket), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os, stde::streams::endianconv::big), m_running(
        false) {
}

TCPClient::~TCPClient() {

}

void TCPClient::sendPacket(protocol::Packet& p) {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    p.send(m_dos);
}

void TCPClient::sendPacket(protocol::Packet* p) {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    p->send(m_dos);
}

void TCPClient::close() {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    m_running = false;
    m_socket.shutdown();
    m_socket.close();
    m_thread.join();
}

void TCPClient::start() {
    if (m_running)
        throw std::runtime_error("Client already running!");

    l << stde::log::level::info << "Connecting..." << std::endl;

    m_running = true;
    m_socket.connect();

    m_thread = std::thread(&TCPClient::run, this);
}

void TCPClient::run() {
    try {
        while (m_running) {
            if (!m_dis)
                break;

            protocol::Packet *packet = protocol::Packet::parse(m_dis);

            m_player->handleSC(packet);

            delete packet;

        }
    } catch (std::exception &e) {
        try {
            m_player->kick("Exception: " + std::string(e.what()));
        } catch (std::exception &e2) {

        }
    }
}
