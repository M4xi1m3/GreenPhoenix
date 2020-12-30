#ifndef INCLUDE_GPPROTOCOL_TYPES_DIRECTION_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_DIRECTION_HPP_
/** @file **/

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents a direction, used by packet 0x0E and 0x0F.
             */
            enum class Direction : int8_t {
                UNKNOWN = -1, DOWN = 0, UP = 1, NORTH = 2, SOUTH = 3, WEST = 4, EAST = 5
            };

            /**
             * Get string representation of a direction
             * @param d Direction to get the string representation of.
             * @return  String representation of d.
             */
            std::string directionName(Direction d);
        }
    }
}

#endif
