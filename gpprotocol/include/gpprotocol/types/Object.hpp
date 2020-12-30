#ifndef INCLUDE_GPPROTOCOL_TYPES_OBJECT_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_OBJECT_HPP_
/** @file **/

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents an object or a vehicle that can be spawned by packet 0x17
             */
            enum class Object : int8_t {
                BOAT = 1, MINECART = 10, MINECART_CHEST = 11, MINECART_FURNACE = 12, PRIMED_TNT = 50, ARROW = 60, SNOWBALL = 61, FISH = 90, UNKNOWN = -1
            };

            /**
             * Get string representation of an object
             * @param o Object to get string representation of
             * @return  String representation of o
             */
            std::string objectName(Object o);
        }
    }
}
#endif
