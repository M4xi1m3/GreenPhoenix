#include <exception>
#include <sstream>

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/Packets.hpp"

using namespace gp::protocol;

#define add_packet(PACKET) \
        case packets::PACKET::getID(): { \
            packets::PACKET* p = new packets::PACKET(); \
            p->read(dis); \
            return p; \
        }

Packet* Packet::parse(stde::streams::data_istream& dis) {
    uint8_t id = dis.read_ubyte();

    switch (id) {
        add_packet(Packet00Ping)
        add_packet(Packet01Login)
        add_packet(Packet02Handshake)
        add_packet(Packet03Chat)
        add_packet(Packet04Time)
        add_packet(Packet05PlayerInventory)
        add_packet(Packet06SpawnPosition)
        add_packet(Packet07UseEntity)
        add_packet(Packet08Health)
        add_packet(Packet09Respawn)
        add_packet(Packet0APlayer)
        add_packet(Packet0BPlayerPosition)

        add_packet(PacketFFKick)

        default:
            std::ostringstream ss;
            ss << "Unknown packet ID " << id << "!";
            throw std::runtime_error(ss.str());
    }

    return nullptr;
}

std::ostream& operator<<(std::ostream& os, gp::protocol::Packet const& p) {
    p.debug(os);
    return os;
}

std::ostream& operator<<(std::ostream& os, gp::protocol::Packet const* p) {
    p->debug(os);
    return os;
}
