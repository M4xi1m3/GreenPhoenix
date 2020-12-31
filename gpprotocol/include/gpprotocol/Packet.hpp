#ifndef INCLUDE_GPPROTOCOL_PACKET_HPP_
#define INCLUDE_GPPROTOCOL_PACKET_HPP_

#include <ostream>
#include "stde/streams/data.hpp"

// Not clean but works well enough.
#define packetID(THE_ID) \
            /** \
             * Get the ID associated with the packet's class. \
             * All Packet **MUST** implement this, as it's used for packet resolution. \
             * \
             * @return  Packet ID. \
             */ \
            constexpr static uint8_t getID() { \
                return THE_ID; \
            } \
\
            /** \
             * ID of the packet, used when sending. \
             * \
             * @return  Packet ID.\
             */ \
            virtual uint8_t id() const { \
                return THE_ID; \
            }

namespace gp {
    namespace protocol {
        /**
         * @brief Represents a packet received / sent by the server.
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

            packetID(0x42)

            /**
             * Reads a packet from a stream.
             * @param dis   Stream to read from
             * @return      New packet
             */
            static Packet* parse(stde::streams::data_istream& dis);

            /**
             * Writes a whole packet to dos and flushes it
             * @param dos   Stream to write to.
             */
            void send(stde::streams::data_ostream& dos);

        };
    }
}

std::ostream& operator<<(std::ostream& os, const gp::protocol::Packet& p);
std::ostream& operator<<(std::ostream& os, const gp::protocol::Packet* p);

#endif
