#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET35BLOCKCHANGE_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET35BLOCKCHANGE_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent by the server when a block changes
             */
            class Packet35BlockChange: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet35BlockChange() : x(0), y(0), z(0), block_id(0), metadata(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet35BlockChange() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_int();
                    y = dis.read_byte();
                    z = dis.read_int();

                    block_id = dis.read_byte();
                    metadata = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(x);
                    dos.write_byte(y);
                    dos.write_int(z);

                    dos.write_byte(block_id);
                    dos.write_byte(metadata);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "BlockChange [x: " << x << "; y: " << +y << "; z: " << z << "; id: " << +block_id << "; metadata: " << +metadata << "]";
                }

                packetID(0x35)

                /**
                 * Block X coordinate
                 */
                int32_t x;

                /**
                 * Block Y coordinate
                 */
                int8_t y;

                /**
                 * Block Z coordinate
                 */
                int32_t z;

                /**
                 * ID of the new block
                 */
                int8_t block_id;

                /**
                 * Metadata of the new block
                 */
                int8_t metadata;
            };

        }
    }
}

#endif
