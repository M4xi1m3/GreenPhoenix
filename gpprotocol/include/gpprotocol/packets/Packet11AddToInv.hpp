#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET11ADDTOINV_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET11ADDTOINV_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Item.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the server when a player has become close enough to collect an item on the ground.
             */
            class Packet11AddToInv: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet11AddToInv() {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet11AddToInv() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    item.id = dis.read_short();
                    item.count = dis.read_byte();
                    item.damage = dis.read_short();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_short(item.id);
                    dos.write_byte(item.count);
                    dos.write_short(item.damage);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "AddToInv [id: " << "; count: " << "; damage:" << "]";
                }

                packetID(0x11)

                /**
                 * Item to add.
                 */
                types::Item item;
            };

        }
    }
}

#endif
