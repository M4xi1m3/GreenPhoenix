#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0EDIGGING_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0EDIGGING_HPP_

#include "gpprotocol/Packet.hpp"

#include "gpprotocol/types/DigStatus.hpp"
#include "gpprotocol/types/Direction.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent by the client when digging.
             */
            class Packet0EDigging: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet0EDigging() : status(types::DigStatus::UNKNOWN), x(0), y(0), z(0), face(types::Direction::UNKNOWN) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0EDigging() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    status = (types::DigStatus) dis.read_byte();
                    x = dis.read_int();
                    y = dis.read_byte();
                    z = dis.read_int();
                    face = (types::Direction) dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_byte((int8_t) status);
                    dos.write_int(x);
                    dos.write_byte(y);
                    dos.write_int(z);
                    dos.write_byte((int8_t) face);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Digging [status: " << types::digStatusName(status) << "; x: " << +x << "; y: " << +y << "; z: " << +z << "; face: "
                            << types::directionName(face) << "]";
                }

                packetID(0x0E)

                /**
                 * Status of the diggind
                 */
                types::DigStatus status;

                /**
                 * Block X position
                 */
                int32_t x;

                /**
                 * Block Y position
                 */
                int8_t y;

                /**
                 * Block Z position
                 */
                int32_t z;

                /**
                 * Face the player is digging
                 */
                types::Direction face;
            };

        }
    }
}

#endif
