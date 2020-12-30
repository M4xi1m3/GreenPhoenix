#ifndef INCLUDE_GPPROTOCOL_TYPES_PLAYERINVENTORY_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_PLAYERINVENTORY_HPP_
/** @file **/

#include <cstdint>
#include <exception>
#include <vector>

#include "Item.hpp"

namespace gp {
    namespace protocol {
        namespace types {

            /**
             * @brief Type of inventory (used for networking).
             */
            enum class PlayerInventoryType : int32_t {
                UNKNOWN = 0, MAIN = -1, ARMOR = -2, CRAFT = -3
            };

            /**
             * @brief Represents a player inventory.
             */
            class PlayerInventory {
            public:
                /**
                 * Constructor
                 */
                PlayerInventory() : type(PlayerInventoryType::UNKNOWN) {

                }
                /**
                 * Constructor
                 * @param size  Size of the inventory
                 */
                PlayerInventory(int16_t size) : type(PlayerInventoryType::UNKNOWN), m_content(size) {
                }

                /**
                 * Constructor
                 * @param size  Size of the inventory
                 * @param type  Type of the inventory
                 */
                PlayerInventory(int16_t size, PlayerInventoryType type) : type(type), m_content(size) {

                }

                /**
                 * Access Item inside inventory
                 * @param i Index
                 * @return  The item at index i.
                 */
                Item operator [](int i) const {
                    if (i > m_content.size() || i < 0)
                        throw std::out_of_range("Trying to access invalid item slot!");

                    return m_content[i];
                }

                /**
                 * Access Item inside inventory
                 * @param i Index
                 * @return  Reference to the item at index i.
                 */
                Item& operator [](int i) {
                    if (i > m_content.size() || i < 0)
                        throw std::out_of_range("Trying to access invalid item slot!");

                    return m_content[i];
                }

                /**
                 * Get size of the inventory
                 * @return  The size of the inventory
                 */
                const int16_t size() const {
                    return m_content.size();
                }

                /**
                 * Destructor.
                 */
                virtual ~PlayerInventory() {
                }

                /**
                 * Type of the directory
                 * @see InventoryType
                 */
                PlayerInventoryType type;
            private:
                std::vector<Item> m_content;

            };

        }
    }
}

#endif
