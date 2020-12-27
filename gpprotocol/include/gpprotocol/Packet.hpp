#ifndef INCLUDE_GPPROTOCOL_PACKET_HPP_
#define INCLUDE_GPPROTOCOL_PACKET_HPP_

#include <ostream>
#include "stde/streams/data.hpp"

namespace gp {
    namespace protocol {
        /**
         * Represents a packet received / sent by the server.
         */
        class Packet {
        public:
            /**
             * Constructor.
             */
            Packet() {

            }

            /**
             * Destructor
             */
            virtual ~Packet() {

            }

            /**
             * Reads packet from stream.
             * @param dis   Input stream.
             */
            virtual void read(stde::streams::data_istream& dis) = 0;

            /**
             * Write packet to stream.
             * @param dos   Output stream.
             */
            virtual void write(stde::streams::data_ostream& dos) const = 0;

            /**
             * Print an human-readable representation of the packet.
             * @param out   Output stream to write to.
             */
            virtual void debug(std::ostream& out) const = 0;

            /**
             * Get the ID associated with the packet's class.
             * All Packet **MUST** implement this, as it's used for packet resolution.
             *
             * @return  Packet ID.
             */
            constexpr static int getID() {
                return -1;
            }

            static Packet* parse(stde::streams::data_istream& dis);

        };
    }
}

std::ostream& operator<<(std::ostream& os, const gp::protocol::Packet& p);
std::ostream& operator<<(std::ostream& os, const gp::protocol::Packet* p);

#endif
