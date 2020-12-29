#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET20ENTITYLOOK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET20ENTITYLOOK_HPP_

#include "gpprotocol/packets/Packet1EEntity.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent by the server when an entity rotates.
             */
            class Packet20EntityLook: public Packet1EEntity {
            public:
                /**
                 * Constructor.
                 */
                Packet20EntityLook() : Packet1EEntity(), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet20EntityLook() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    Packet1EEntity::read(dis);
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    Packet1EEntity::write(dos);
                    dos.write_byte(yaw);
                    dos.write_byte(pitch);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "EntityMove [eid: " << eid << "; yaw: " << +yaw << "; pitch: " << +pitch << "]";
                }

                packetID(0x20)

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
