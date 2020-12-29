#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET22ENTITYTELEPORT_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET22ENTITYTELEPORT_HPP_

#include "gpprotocol/packets/Packet1EEntity.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent to the server when an entity moves more than 4 blocks.
             */
            class Packet22EntityTeleport: public Packet1EEntity {
            public:
                /**
                 * Constructor.
                 */
                Packet22EntityTeleport() : Packet1EEntity(), x(0), y(0), z(0), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet22EntityTeleport() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    Packet1EEntity::read(dis);
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    Packet1EEntity::write(dos);
                    dos.write_int(x);
                    dos.write_int(y);
                    dos.write_int(z);
                    dos.write_byte(yaw);
                    dos.write_byte(pitch);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "EntityMove [eid: " << eid << "; x: " << x << "; y: " << y << "; z: " << z << "; yaw: " << yaw << "; pitch: " << pitch << "]";
                }

                packetID(0x22)

                /**
                 * Relative movement along the X axis.
                 */
                int32_t x;

                /**
                 * Relative movement along the Y axis.
                 */
                int32_t y;

                /**
                 * Relative movement along the Z axis.
                 */
                int32_t z;

                /**
                 * Entity's rotation around the X axis.
                 */
                int8_t yaw;

                /**
                 * Entity's rotation around the Y axis.
                 */
                int8_t pitch;
            };

        }
    }
}

#endif
