#ifndef INCLUDE_GPPROTOCOL_TYPES_ANIMATION_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_ANIMATION_HPP_
/** @file **/

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents an entity animation
             */
            enum class Animation : int8_t {
                NONE = 0, SWING = 1, DEATH = 2,

                BOAT = 100, NOT_BOAT = 101, FIRE = 102, NOT_FIRE = 103, CROUCHING = 104, NOT_CROUCHING = 105
            };

            /**
             * Get string representation of an Animation
             * @param a Animation to get the representation of
             * @return  String representation of a
             */
            std::string animationName(Animation a);
        }
    }
}

#endif
