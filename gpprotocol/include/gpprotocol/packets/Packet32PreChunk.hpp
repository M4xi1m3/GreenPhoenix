#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET32PRECHUNK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET32PRECHUNK_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet is sent by the server to notify the client to initialize or unload a chunk.
             */
            class Packet32PreChunk: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet32PreChunk() : x(0), z(0), init(false) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet32PreChunk() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_int();
                    z = dis.read_int();
                    init = dis.read_bool();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(x);
                    dos.write_int(z);
                    dos.write_bool(init);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "PreChunk [x: " << x << "; z: " << z << "; init: " << +init << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x32;
                }

                /**
                 * Chunk X coordinate
                 */
                int32_t x;

                /**
                 * Chunk Z coordinate
                 */
                int32_t z;

                /**
                 * If true, the client will initialize the chunk, if false, it will unload it.
                 */
                bool init;
            };

        }
    }
}

#endif
