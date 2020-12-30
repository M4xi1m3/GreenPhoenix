#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET15PICKUPSPAWN_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET15PICKUPSPAWN_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Item.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent whenever an item on the ground (say a pickaxe thrown on the ground) comes into range of the player.
             */
            class Packet15PickupSpawn: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet15PickupSpawn() : eid(0), x(0), y(0), z(0), yaw(0), pitch(0), roll(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet15PickupSpawn() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    item.id = dis.read_short();
                    item.count = dis.read_byte();
                    item.damage = 0;
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                    roll = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_short(item.id);
                    dos.write_byte(item.count);
                    dos.write_int(x);
                    dos.write_int(y);
                    dos.write_int(z);
                    dos.write_byte(yaw);
                    dos.write_byte(pitch);
                    dos.write_byte(roll);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "PickupSpawn [eid: " << eid << "; id: " << +item.id << "; count: " << +item.count << "; x: " << x << "; y: " << y << "; z:" << z
                            << "; yaw: " << +yaw << "; pitch: " << +pitch << "; roll: " << +roll << "]";
                }

                packetID(0x15)

                /**
                 * Entity ID of the entity
                 */
                int32_t eid;

                /**
                 * Item to spawn
                 */
                types::Item item;

                /**
                 * Item's X position
                 */
                int32_t x;

                /**
                 * Item's Y position
                 */
                int32_t y;

                /**
                 * Item's Y position
                 */
                int32_t z;

                /**
                 * Item's rotation around the X axis
                 */
                int8_t yaw;

                /**
                 * Item's rotation around the Y axis
                 */
                int8_t pitch;

                /**
                 * Item's rotation around the Z axis
                 */
                int8_t roll;
            };

        }
    }
}

#endif
