#include <exception>
#include <sstream>

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/Packets.hpp"

using namespace gp::protocol;

// TODO: Find a better way to do this, preferably at run-time instead of static, for modularity.
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
        add_packet(Packet0CPlayerLook)
        add_packet(Packet0DPlayerPositionLook)
        add_packet(Packet0EDigging)
        add_packet(Packet0FPlacement)
        add_packet(Packet10HlodingChange)
        add_packet(Packet11AddToInv)
        add_packet(Packet12Animation)

        add_packet(Packet14NamedEntitySpawn)
        add_packet(Packet15PickupSpawn)
        add_packet(Packet16CollectItem)
        add_packet(Packet17AddObject)
        add_packet(Packet18MobSpawn)

        add_packet(Packet1CEntityVelocity)
        add_packet(Packet1DDestroyEntity)
        add_packet(Packet1EEntity)
        add_packet(Packet1FEntityMove)
        add_packet(Packet20EntityLook)
        add_packet(Packet21EntityMoveLook)
        add_packet(Packet22EntityTeleport)

        add_packet(Packet26EntityStatus)
        add_packet(Packet27AttachEntity)

        add_packet(Packet32PreChunk)
        add_packet(Packet33MapChunk)
        add_packet(Packet34MultiBlock)
        add_packet(Packet35BlockChange)

        add_packet(Packet3BTileEntity)
        add_packet(Packet3CExplosion)

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
