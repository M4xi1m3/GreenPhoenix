#ifndef INCLUDE_GPPROTOCOL_TYPES_ITEM_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_ITEM_HPP_

#include <cstdint>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * @brief Represents an item stack inside an inventory.
             * @see Inventory
             */
            class Item {
            public:
                /**
                 * Constructor
                 */
                Item() : id(-1), count(0), damage(0) {

                }

                /**
                 * Constructor
                 * @param id    Id of the item
                 * @param count Number of items
                 */
                Item(int16_t id, int8_t count) : id(id), count(count), damage(0) {

                }

                /**
                 * Constructor
                 * @param id    Id of the item
                 * @param count Number of the item
                 * @param damage    Damages of the items.
                 */
                Item(int16_t id, int8_t count, int16_t damage) : id(id), count(count), damage(damage) {

                }

                /**
                 * Destructor
                 */
                virtual ~Item() {

                }

                /**
                 * Item id. Should be -1 for empty stack.
                 */
                int16_t id;

                /**
                 * Number of items. 0 for empty stack.
                 */
                int8_t count;

                /**
                 * Damage. Only applies to tools and armor, 0 for other items.
                 * 0 means the item hasn't been used.
                 */
                int16_t damage;

            };
        }
    }
}

#endif
