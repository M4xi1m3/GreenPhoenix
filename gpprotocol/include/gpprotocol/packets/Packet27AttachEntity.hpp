#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET27ATTACHENTITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET27ATTACHENTITY_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Status.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent when a player has been attached to an entity (e.g. Minecart).
             *
             * If vehicle EID is -1, then it's detaching.
             */
            class Packet27AttachEntity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet27AttachEntity() : eid(0), vehicle_eid(-1) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet27AttachEntity() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    vehicle_eid = dis.read_int();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_int(vehicle_eid);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "AttachEntity [eid: " << eid << "; vehicle: " << vehicle_eid << "]";
                }

                packetID(0x27)

                /**
                 * EID of the entity being attached
                 */
                int32_t eid;

                /**
                 * EID of the entity we attach to
                 */
                int32_t vehicle_eid;
            };

        }
    }
}

#endif
