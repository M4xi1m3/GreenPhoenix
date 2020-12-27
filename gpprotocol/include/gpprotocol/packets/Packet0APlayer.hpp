#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0APLAYER_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0APLAYER_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Contains state of the client.
             */
            class Packet0APlayer: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet0APlayer() : onground(false) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0APlayer() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    onground = dis.read_bool();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_bool(onground);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Player [onground: " << +onground << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x0A;
                }

                /**
                 * If the player is on ground or not.
                 */
                bool onground;
            };

        }
    }
}

#endif
