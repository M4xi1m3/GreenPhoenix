#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET33MAPCHUNK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET33MAPCHUNK_HPP_

#include "gpprotocol/Packet.hpp"
#include <vector>

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief The client will overwrite all or part of a chunk using the region of data contained in this packet.
             */
            class Packet33MapChunk: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet33MapChunk() : x(0), y(0), z(0), size_x(0), size_y(0), size_z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet33MapChunk() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_int();
                    y = dis.read_short();
                    z = dis.read_int();

                    size_x = dis.read_byte();
                    size_y = dis.read_byte();
                    size_z = dis.read_byte();

                    data.clear();

                    int32_t size = dis.read_int();
                    data.resize(size);
                    dis.read((char*) data.data(), size);
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(x);
                    dos.write_short(y);
                    dos.write_int(z);

                    dos.write_byte(size_x);
                    dos.write_byte(size_y);
                    dos.write_byte(size_z);

                    dos.write_int(data.size());
                    dos.write((char*) data.data(), data.size());
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "MapChunk [x: " << x << "; y: " << y << "; z: " << z << "; size_x: " << size_x << "; size_y: " << size_y << "; size_z: " << size_z
                            << "; data: " << data.size() << " bytes]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x33;
                }

                /**
                 * Block X coordinate
                 */
                int32_t x;

                /**
                 * Block Y coordinate
                 */
                int16_t y;

                /**
                 * Block Z coordinate
                 */
                int32_t z;

                /**
                 * Size of the region on the X axis (actual size -1)
                 */
                int8_t size_x;

                /**
                 * Size of the region on the y axis (actual size -1)
                 */
                int8_t size_y;

                /**
                 * Size of the region on the Z axis (actual size -1)
                 */
                int8_t size_z;

                /**
                 * Data compressed using zlib's DEFLATE
                 */
                std::vector<int8_t> data;

            };

        }
    }
}

#endif
