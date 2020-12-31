#include "gpproxy/ProxyPlayer.hpp"

#include "gpprotocol/packets/PacketFFKick.hpp"
#include "gpprotocol/packets/Packet03Chat.hpp"

using namespace gp::proxy;

stde::log::log ProxyPlayer::l = stde::log::log::get("proxy-player");

ProxyPlayer::ProxyPlayer(ProxyHandler* handler) : m_handler(handler) {

}

ProxyPlayer::~ProxyPlayer() {
}

void ProxyPlayer::sendPacket(protocol::Packet& packet) {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    packet.send(m_handler->m_dos);
}

void ProxyPlayer::sendPacket(protocol::Packet* packet) {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    packet->send(m_handler->m_dos);
}

void ProxyPlayer::kick(const std::string& reason) {
    protocol::packets::PacketFFKick p;
    p.reason = reason;
    sendPacket(p);
}

void ProxyPlayer::sendChat(const std::string& message) {
    protocol::packets::Packet03Chat p;
    p.message = message;
    sendPacket(p);
}

void ProxyPlayer::handleCS(protocol::Packet* packet) {
    l << stde::log::level::debug << "[C->S]#" << m_handler->getID() << " " << packet << std::endl;

    m_handler->m_client->sendPacket(packet);
}

void ProxyPlayer::handleSC(protocol::Packet* packet) {
    l << stde::log::level::debug << "[S->C]#" << m_handler->getID() << " " << packet << std::endl;

    sendPacket(packet);
}
