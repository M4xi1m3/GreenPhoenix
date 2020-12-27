#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET04TIME_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET04TIME_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent to the client to indicate the time changed.
             */
            class Packet04Time: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet04Time() : time(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet04Time() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    time = dis.read_long();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_long(time);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Time [time: " << time << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x04;
                }

                /**
                 * Time of the world
                 */
                int64_t time;
            };

        }
    }
}

#endif
