#include <gpproxy/ProxyHandler.hpp>
#include "gpprotocol/Packet.hpp"

using namespace gp::proxy;

stde::log::log ProxyHandler::l = stde::log::log::get("proxy-handler");

ProxyHandler::~ProxyHandler() {
}

void ProxyHandler::handle() {
    l << stde::log::level::info << "Accepted connection from " << m_socket.peer_address() << "." << std::endl;

    m_player = new ProxyPlayer(this);

    try {
        m_client = new TCPClient(m_player, "127.0.0.1:25566");
        m_client->start();

        while (m_running) {
            try {
                if (m_dis.eof())
                    break;

                protocol::Packet *packet = protocol::Packet::parse(m_dis);

                m_player->handleCS(packet);

                delete packet;
            } catch (std::exception &e) {
                try {
                    m_player->kick("Exception: " + std::string(e.what()));
                } catch (std::exception &e1) {
                }
            }
        }

        m_client->close();
    } catch (std::exception &e) {
        if (m_running) {
            try {
                m_player->kick("Exception: " + std::string(e.what()));
                m_client->close();
            } catch (std::exception &e) {
            }
        }
    }

    if (m_client != nullptr) {
        delete m_client;
        m_client = nullptr;
    }

    delete m_player;
}

void ProxyHandler::stop() {
    m_socket.shutdown();
    m_socket.close();
    m_running = false;
}
