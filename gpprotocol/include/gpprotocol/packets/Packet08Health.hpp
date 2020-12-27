#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET08HEALTH_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET00PING_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Updates the health of the client.
             */
            class Packet08Health: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet08Health() : health(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet08Health() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    health = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_byte(health);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Health [health: " << health << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x08;
                }

                /**
                 * Helth value
                 */
                int8_t health;
            };

        }
    }
}

#endif
