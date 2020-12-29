#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET1EENTITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET1EENTITY_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Super-packet for other entities packets. When sent to the client, it may initialize the entry.
             */
            class Packet1EEntity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet1EEntity() : eid(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet1EEntity() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Entity [eid: " << eid << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x1E;
                }

                /**
                 * EID of the entity
                 */
                int32_t eid;
            };

        }
    }
}

#endif
