#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0FPLACEMENT_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0FPLACEMENT_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Direction.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Packet sent by the client when placing a block.
             */
            class Packet0FPlacement: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet0FPlacement() : id(0), x(0), y(0), z(0), face(types::Direction::UNKNOWN) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0FPlacement() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    id = dis.read_short();
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
                    dos.write_short(id);
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
                    out << "BlockPlacement [id: " << id << "; x: " << x << "; y: " << y << "; z: " << z << "; face: " << types::directionName(face) << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x00;
                }

                /**
                 * ID of the block to place
                 */
                int16_t id;

                /**
                 * X position of the block to place on
                 */
                int32_t x;

                /**
                 * Y position of the block to place on
                 */
                int8_t y;

                /**
                 * Z position of the block to place on
                 */
                int32_t z;

                /**
                 * Face of the block to place on
                 */
                types::Direction face;
            };

        }
    }
}

#endif
