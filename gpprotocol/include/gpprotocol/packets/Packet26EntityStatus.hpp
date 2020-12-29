#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET26ENTITYSTATUS_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET26ENTITYSTATUS_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Status.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Indication of entity damage, death, explosion.
             */
            class Packet26EntityStatus: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet26EntityStatus() : eid(0), status(types::Status::UNKNOWN) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet26EntityStatus() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    status = (types::Status) dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_byte((int8_t) status);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "DestroyEntity [eid: " << eid << "; status: " << types::statusnName(status) << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x26;
                }

                /**
                 * EID of the entity
                 */
                int32_t eid;

                /**
                 * Status of the entity
                 */
                types::Status status;
            };

        }
    }
}

#endif
