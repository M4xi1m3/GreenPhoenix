#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET05PLAYERINVENTORY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET05PLAYERINVENTORY_HPP_

#include <gpprotocol/types/PlayerInventory.hpp>
#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sends the inventory of a player.
             * @see PlayerInventory
             */
            class Packet05PlayerInventory: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet05PlayerInventory() {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet05PlayerInventory() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    types::PlayerInventoryType type = (types::PlayerInventoryType) dis.read_int();
                    int16_t size = dis.read_short();

                    inventory = types::PlayerInventory(size, type);

                    for (int i = 0; i < inventory.size(); i++) {
                        int16_t id = dis.read_short();
                        if (id == -1) {
                            inventory[i] = types::Item();
                        } else {
                            int8_t count = dis.read_byte();
                            int16_t damage = dis.read_short();

                            inventory[i] = types::Item(id, count, damage);
                        }
                    }
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int((int32_t) inventory.type);
                    dos.write_short(inventory.size());

                    for (int i = 0; i < inventory.size(); i++) {
                        types::Item item = inventory[i];
                        if (item.count == 0 || item.id == -1) {
                            dos.write_short(-1);
                        } else {
                            dos.write_short(item.id);
                            dos.write_byte(item.count);
                            dos.write_short(item.damage);
                        }
                    }

                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Inventory [" << +(int) inventory.type << "]";
                }

                packetID(0x05)

                /**
                 * Inventory
                 */
                types::PlayerInventory inventory;
            };

        }
    }
}

#endif
