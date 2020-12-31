#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET03CHAT_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET03CHAT_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Represents a chat massage
             */
            class Packet03Chat: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet03Chat() : message("") {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet03Chat() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    message = dis.read_string();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_string(message);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Chat [message: " << message << "]";
                }

                /**
                 * Message
                 */
                std::string message;

                packetID(0x03)
            };

        }
    }
}

#endif
