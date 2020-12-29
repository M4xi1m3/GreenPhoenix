#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET16COLLECTITEM_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET16COLLECTITEM_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the server when someone picks up an item lying on the ground (only for animation).
             */
            class Packet16CollectItem: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet16CollectItem() : item_eid(0), player_eid(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet16CollectItem() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    item_eid = dis.read_int();
                    player_eid = dis.read_int();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(item_eid);
                    dos.write_int(player_eid);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "CollectItem [iEID: " << item_eid << ";pEID" << player_eid << "]";
                }

                packetID(0x16)

                /**
                 * EID of the picked up item
                 */
                int32_t item_eid;

                /**
                 * EID of the player picking the item up
                 */
                int32_t player_eid;
            };

        }
    }
}

#endif
