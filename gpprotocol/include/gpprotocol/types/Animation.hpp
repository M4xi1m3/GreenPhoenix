#ifndef INCLUDE_GPPROTOCOL_TYPES_ANIMATION_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_ANIMATION_HPP_

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

                UNK100 = 100, UNK101 = 101, UNK102 = 102, UNK103 = 103, UNK104 = 104, UNK105 = 105
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
