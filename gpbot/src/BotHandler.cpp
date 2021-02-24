#include "gpbot/BotHandler.hpp"
#include "gpprotocol/Packets.hpp"

using namespace gp::bot;

void BotHandler::handle(protocol::Packet* packet) {
    // l << stde::log::level::debug << packet << std::endl;

    if (m_login) {
        switch (packet->id()) {
            case 0x01: {
                l << stde::log::level::debug << "Logged in!" << std::endl;
                m_login = false;
                break;
            }
            case 0x02: {
                protocol::packets::Packet01Login p;
                p.version = 6;
                p.username = name;
                p.password = "Password";
                p.seed = 0;
                p.dimmension = 0;
                send(p);
                break;
            }
            case 0xFF: {
                protocol::packets::PacketFFKick *p = dynamic_cast<protocol::packets::PacketFFKick*>(packet);
                l << stde::log::level::debug << "Kicked: " << p->reason << std::endl;
                close();
                break;
            }
            default:
                close();
        }
    } else {
        if (packet->id() == 0) {
            protocol::packets::Packet00Ping p;
            send(p);
        } else if (packet->id() == 0xFF) {
            protocol::packets::PacketFFKick *p = dynamic_cast<protocol::packets::PacketFFKick*>(packet);
            l << stde::log::level::debug << "Kicked: " << p->reason << std::endl;
            close();
        }
    }
}

void BotHandler::stop() {
    protocol::packets::PacketFFKick p;
    p.reason = "Quitting";
    send(p);

    close();
}

void BotHandler::closed() {
}

void BotHandler::started() {
    protocol::packets::Packet02Handshake p;
    p.username = name;
    send(p);
}
