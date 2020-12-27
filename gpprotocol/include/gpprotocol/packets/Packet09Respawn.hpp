#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET09RESPAWN_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET09RESPAWN_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the client to respawn.
             */
            class Packet09Respawn: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet09Respawn() {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet09Respawn() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {

                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {

                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Respawn []";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x09;
                }
            };

        }
    }
}

#endif
