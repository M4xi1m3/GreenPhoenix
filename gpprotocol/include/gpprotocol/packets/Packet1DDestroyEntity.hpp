#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET1DDESTROYENTITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET1DDESTROYENTITY_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the server when an entity is destroyed
             */
            class Packet1DDestroyEntity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet1DDestroyEntity() : eid(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet1DDestroyEntity() {

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
                    out << "DestroyEntity [eid: " << eid << "]";
                }

                packetID(0x1D)

                /**
                 * EID of the destroyed entity
                 */
                int32_t eid;
            };

        }
    }
}

#endif
