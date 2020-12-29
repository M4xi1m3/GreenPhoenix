#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET06_SPAWNPOSITION_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET06_SPAWNPOSITION_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet indicates the spawn position for the player, for the compass.
             */
            class Packet06SpawnPosition: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet06SpawnPosition() : x(0), y(0), z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet06SpawnPosition() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(x);
                    dos.write_int(y);
                    dos.write_int(z);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "SpawnPosition [x: " << x << "; y: " << y << "; z: " << z << "]";
                }

                packetID(0x06)

                /**
                 * Spawn X position
                 */
                int32_t x;

                /**
                 * Spawn Y position
                 */
                int32_t y;

                /**
                 * Spawn Z position
                 */
                int32_t z;
            };

        }
    }
}

#endif
