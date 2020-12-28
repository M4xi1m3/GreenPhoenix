#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET10HOLDINGCHANGE_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET10HOLDINGCHANGE_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent when a player changes item in his hand. This is mostly cosmetic.
             */
            class Packet10HlodingChange: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet10HlodingChange() : eid(0), id(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet10HlodingChange() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    id = dis.read_short();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_short(id);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "HoldingChange [eid: " << eid << "; id: " << id << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x10;
                }

                /**
                 * Player Entity ID.
                 */
                int32_t eid;

                /**
                 * ID of the item.
                 */
                int16_t id;
            };

        }
    }
}

#endif
