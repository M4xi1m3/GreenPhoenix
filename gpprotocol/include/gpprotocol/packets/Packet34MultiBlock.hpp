#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET34MULTIBLOCK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET34MULTIBLOCK_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/MultiBlock.hpp"

#include <vector>

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sends changes made to multiple blocks.
             */
            class Packet34MultiBlock: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet34MultiBlock() : chunk_x(0), chunk_z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet34MultiBlock() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    chunk_x = dis.read_int();
                    chunk_z = dis.read_int();

                    uint16_t size = dis.read_ushort();

                    changes.clear();
                    changes.resize(size);

                    for (int i = 0; i < size; i++) {
                        int16_t coords = dis.read_short();
                        changes[i].x = coords >> 12 & 0x0F;
                        changes[i].z = coords >> 8 & 0x0F;
                        changes[i].y = coords & 0xFF;
                    }
                    for (int i = 0; i < size; i++) {
                        changes[i].type = dis.read_int();
                    }
                    for (int i = 0; i < size; i++) {
                        changes[i].metadata = dis.read_int();
                    }
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(chunk_x);
                    dos.write_int(chunk_z);
                    dos.write_ushort(changes.size());

                    for (int i = 0; i < changes.size(); i++) {
                        int16_t cords = ((changes[i].x & 0x0F) << 12) | ((changes[i].z & 0x0F) << 8) | (changes[i].y & 0xFF);
                        dos.write_short(cords);
                    }
                    for (int i = 0; i < changes.size(); i++) {
                        dos.write_byte(changes[i].type);
                    }
                    for (int i = 0; i < changes.size(); i++) {
                        dos.write_byte(changes[i].metadata);
                    }
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "MultiBlock [chunk_x: " << chunk_x << "; chunk_z: " << chunk_z << "; changes: " << changes.size() << " elements]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x34;
                }

                int32_t chunk_x;
                int32_t chunk_z;

                std::vector<types::MultiBlock> changes;
            };

        }
    }
}

#endif
