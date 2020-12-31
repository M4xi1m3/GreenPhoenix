#include "gpproxy/ProxyPlayer.hpp"
#include "gpproxy/ProxyConfig.hpp"

#include "gpprotocol/Packets.hpp"
#include "gpproxy/TCPClient.hpp"

#include <sstream>
#include <iterator>

#define DEBUG_PACKETS 0

using namespace gp::proxy;

stde::log::log ProxyPlayer::l = stde::log::log::get("proxy-player");

ProxyPlayer::ProxyPlayer(ProxyHandler* handler) : m_handler(handler), name(""), m_swapping(false) {

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

void ProxyPlayer::unloadEntities() {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    for (auto it = entities.begin(); it != entities.end(); it++) {
        protocol::packets::Packet1DDestroyEntity p;
        p.eid = (*it);
        sendPacket(p);
    }
    entities.clear();
}

void ProxyPlayer::swap(std::string ip) {
    const std::lock_guard<std::recursive_mutex> lock(m_mutex);
    m_swapping = true;
    m_handler->m_client->close();
    unloadEntities();
    delete m_handler->m_client;
    m_handler->m_client = new TCPClient(m_handler, this, ip);
    m_handler->m_client->start();
    protocol::packets::Packet02Handshake handshake;
    handshake.username = name;
    m_handler->m_client->sendPacket(handshake);
}

void ProxyPlayer::handleCommand(std::string command) {
    std::stringstream ss(command);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> args(begin, end);

    if (args.size() <= 1) {
        sendChat("[GP] Usage: /gp <command>");
    } else {
        if (args[1] == "ue") {
            sendChat("[GP] Unloading entities");
            unloadEntities();
        } else if (args[1] == "servers") {
            std::string list = "";
            for (auto it = ProxyConfig::server_list.begin(); it != ProxyConfig::server_list.end(); it++) {
                list += " " + (*it).first;
            }
            sendChat("[GP] Server list:" + list);
        } else if (args[1] == "swap") {
            if (args.size() == 3) {
                std::string ip;
                try {
                    ip = ProxyConfig::server_list.at(args[2]);
                } catch (std::exception &e) {
                    sendChat("[GP] Unknown server \"" + args[2] + "\"!");
                }
                swap(ip);
            } else {
                sendChat("[GP] Usage: /gp swap <name>");
            }
        } else {
            sendChat("[GP] Unknown command \"" + args[1] + "\"!");
        }
    }
}

void ProxyPlayer::handleCS(protocol::Packet* packet) {
#if DEBUG_PACKETS
    l << stde::log::level::debug << "[C->S]#" << m_handler->getID() << " " << packet << std::endl;
#endif

    if (m_swapping) {
        if (packet->id() == 0x01) {
            m_handler->m_client->sendPacket(packet);
        }
    } else {
        if (packet->id() == 0x02) {
            protocol::packets::Packet02Handshake *handshake = dynamic_cast<protocol::packets::Packet02Handshake*>(packet);
            name = handshake->username;
            l << stde::log::level::info << "Player " << name << " issued handshake" << std::endl;
        } else if (packet->id() == 0x03) {
            protocol::packets::Packet03Chat *chat = dynamic_cast<protocol::packets::Packet03Chat*>(packet);
            l << stde::log::level::info << "Chat <" << name << "> " << chat->message << std::endl;
            if (chat->message.rfind("/gp", 0) == 0) {
                handleCommand(chat->message);
                return;
            }
        }

        m_handler->m_client->sendPacket(packet);
    }
}

void ProxyPlayer::handleSC(protocol::Packet* packet) {
#if DEBUG_PACKETS
    l << stde::log::level::debug << "[S->C]#" << m_handler->getID() << " " << packet << std::endl;
#endif

    if (m_swapping) {
        if (packet->id() == 0x02) {
            protocol::packets::Packet02Handshake* handshake = dynamic_cast<protocol::packets::Packet02Handshake*>(packet);

            if (handshake->username == "-") {
                protocol::packets::Packet01Login login;

                login.version = 6;
                login.username = name;
                login.password = "Password";
                login.seed = 0;
                login.dimmension = 0;
                m_handler->m_client->sendPacket(login);
            } else {
                kick("[GP] GP doesn't support swapping to online-mode servers!");
            }
        } else if (packet->id() == 0x01) {
            m_swapping = false;
        }
        return;
    }

    if (packet->id() == 0x14) {
        protocol::packets::Packet14NamedEntitySpawn *p = dynamic_cast<protocol::packets::Packet14NamedEntitySpawn*>(packet);
        entities.emplace(p->eid);
    } else if (packet->id() == 0x15) {
        protocol::packets::Packet15PickupSpawn *p = dynamic_cast<protocol::packets::Packet15PickupSpawn*>(packet);
        entities.emplace(p->eid);
    } else if (packet->id() == 0x17) {
        protocol::packets::Packet17AddObject *p = dynamic_cast<protocol::packets::Packet17AddObject*>(packet);
        entities.emplace(p->eid);
    } else if (packet->id() == 0x18) {
        protocol::packets::Packet18MobSpawn *p = dynamic_cast<protocol::packets::Packet18MobSpawn*>(packet);
        entities.emplace(p->eid);
    } else if (packet->id() == 0x1D) {
        protocol::packets::Packet1DDestroyEntity *p = dynamic_cast<protocol::packets::Packet1DDestroyEntity*>(packet);
        entities.erase(p->eid);
    }

    sendPacket(packet);
}
