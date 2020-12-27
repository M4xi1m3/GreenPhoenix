#ifndef INCLUDE_GPPROTOCOL_TYPES_PLAYERINVENTORY_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_PLAYERINVENTORY_HPP_

#include <cstdint>
#include <exception>

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
                PlayerInventory() : m_size(0), type(PlayerInventoryType::UNKNOWN), m_content(nullptr) {

                }
                /**
                 * Constructor
                 * @param size  Size of the inventory
                 */
                PlayerInventory(int16_t size) : m_size(size), type(PlayerInventoryType::UNKNOWN), m_content(new Item[size]) {

                }

                /**
                 * Constructor
                 * @param size  Size of the inventory
                 * @param type  Type of the inventory
                 */
                PlayerInventory(int16_t size, PlayerInventoryType type) : m_size(size), type(type), m_content(new Item[size]) {

                }

                /**
                 * Access Item inside inventory
                 * @param i Index
                 * @return  The item at index i.
                 */
                Item operator [](int i) const {
                    if (i > m_size || m_content == nullptr)
                        throw std::out_of_range("Trying to access invalid item slot!");

                    return m_content[i];
                }

                /**
                 * Access Item inside inventory
                 * @param i Index
                 * @return  Reference to the item at index i.
                 */
                Item& operator [](int i) {
                    if (i > m_size || m_content == nullptr)
                        throw std::out_of_range("Trying to access invalid item slot!");

                    return m_content[i];
                }

                /**
                 * Get size of the inventory
                 * @return  The size of the inventory
                 */
                const int16_t size() const {
                    return m_size;
                }

                /**
                 * Destructor.
                 */
                virtual ~PlayerInventory() {
                    if (m_content != nullptr)
                        delete[] m_content;
                }

                /**
                 * Type of the directory
                 * @see InventoryType
                 */
                PlayerInventoryType type;
            private:
                int16_t m_size;
                Item *m_content;

            };

        }
    }
}

#endif
