#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET21ENTITYMOVELOOK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET21ENTITYMOVELOOK_HPP_

#include "gpprotocol/packets/Packet1EEntity.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent to the server when an entity moves less than 4 blocks and rotated.
             *
             * Movement is stored as difference between old and new coordinate, divided by 32, cast to an int.
             */
            class Packet21EntityMoveLook: public Packet1EEntity {
            public:
                /**
                 * Constructor.
                 */
                Packet21EntityMoveLook() : Packet1EEntity(), move_x(0), move_y(0), move_z(0), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet21EntityMoveLook() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    Packet1EEntity::read(dis);
                    move_x = dis.read_byte();
                    move_y = dis.read_byte();
                    move_z = dis.read_byte();
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    Packet1EEntity::write(dos);
                    dos.write_byte(move_x);
                    dos.write_byte(move_y);
                    dos.write_byte(move_z);
                    dos.write_byte(yaw);
                    dos.write_byte(pitch);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "EntityMoveLook [eid: " << eid << "; Mx: " << +move_x << "; My: " << +move_y << "; Mz: " << +move_z << "; yaw: " << +yaw << "; pitch: "
                            << +pitch << "]";
                }

                packetID(0x21)

                /**
                 * Relative movement along the X axis.
                 */
                int8_t move_x;

                /**
                 * Relative movement along the Y axis.
                 */
                int8_t move_y;

                /**
                 * Relative movement along the Z axis.
                 */
                int8_t move_z;

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
