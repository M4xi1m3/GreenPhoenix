#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET00PING_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET00PING_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet may be sent by the client to keep the connection alive.
             */
            class Packet00Ping: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet00Ping() {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet00Ping() {

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
                    out << "Ping []";
                }

                packetID(0x00)
            };

        }
    }
}

#endif
