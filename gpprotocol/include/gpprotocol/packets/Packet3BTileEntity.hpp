#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET3BTILEENTITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET3BTILEENTITY_HPP_

#include "gpprotocol/Packet.hpp"
#include <vector>

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This is a complex packet used to send tile entities including their entire NBT representation.
             */
            class Packet3BTileEntity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet3BTileEntity() : x(0), y(0), z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet3BTileEntity() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_int();
                    y = dis.read_byte();
                    z = dis.read_int();
                    uint16_t size = dis.read_ushort();
                    data.clear();
                    data.resize(size);
                    dis.read((char*) data.data(), size);
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(x);
                    dos.write_byte(y);
                    dos.write_int(z);
                    dos.write_ushort(data.size());
                    dos.write((char*) data.data(), data.size());
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "TileEntity [x: " << x << "; y: " << +y << "; z: " << z << "; data: " << data.size() << " bytes]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x3B;
                }

                /**
                 * TileEntnty's X position
                 */
                int32_t x;

                /**
                 * TileEntnty's Y position
                 */
                int8_t y;

                /**
                 * TileEntnty's Z position
                 */
                int32_t z;

                /**
                 * GZip compressed NBT data
                 */
                std::vector<int8_t> data;

            };

        }
    }
}

#endif
