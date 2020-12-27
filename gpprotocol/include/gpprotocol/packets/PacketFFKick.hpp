#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKETFFKICK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKETFFKICK_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * Sent by a client when leaving properly or by the server to kick the client.
             */
            class PacketFFKick: public Packet {
            public:
                /**
                 * Constructor.
                 */
                PacketFFKick() : reason("") {

                }

                /**
                 * Destructor
                 */
                virtual ~PacketFFKick() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    reason = dis.read_string();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_string(reason);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Kick [reason: " << reason << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0xFF;
                }

                std::string reason;
            };
        }
    }
}

#endif /* INCLUDE_GPPROTOCOL_PACKETS_PACKETFFKICK_HPP_ */
