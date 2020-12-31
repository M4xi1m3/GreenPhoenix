#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET02HANDSHAKE_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET02HANDSHAKE_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This is the first packet sent when the client connects and is used for Authentication.
             */
            class Packet02Handshake: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet02Handshake() : username("") {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet02Handshake() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    username = dis.read_string();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_string(username);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Handshake [username: " << username << "]";
                }

                /**
                 * Username
                 */
                std::string username;

                packetID(0x02)
            };
        }
    }
}

#endif
