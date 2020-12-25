#include "gpnet/TCPServer.hpp"

#include <iostream>

using namespace gp::net;

stde::log::log TCPServer::l = stde::log::log::get("Net");

TCPServer::TCPServer(std::string ip, int port) : m_address(ip, std::to_string(port)), m_socket(m_address), m_running(false), m_mustStop(true) {
}

TCPServer::~TCPServer() {
    // TODO Auto-generated destructor stub
}

void TCPServer::start() {
    if (m_running)
        throw std::runtime_error("Server already running!");

    m_mustStop = false;

    m_thread = std::thread(&TCPServer::run, this);
}

void TCPServer::stop() {
    if (!m_running)
        throw std::runtime_error("Server not running!");

    l << stde::log::level::info << "Stopping TCP server..." << std::endl;

    m_mustStop = true;
    m_thread.join();
}

void TCPServer::run() {
    l << stde::log::level::info << "Starting TCP server on " << m_address << "..." << std::endl;

    m_socket.reuse_address(true);
    m_socket.blocking(false);
    m_socket.bind();
    m_socket.listen();

    m_running = true;

    // Run until we must stop
    while (!m_mustStop) {
        try {
            // Accept as much as we can before EWOULDBLOCK.
            while(!m_mustStop) {
                stde::net::sock client_socket = m_socket.accept();
            }
        } catch (const std::system_error &e) {

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    m_running = false;
}
