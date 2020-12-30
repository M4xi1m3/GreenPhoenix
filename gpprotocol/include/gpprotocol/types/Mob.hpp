#ifndef INCLUDE_GPPROTOCOL_TYPES_MOB_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_MOB_HPP_
/** @file **/

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents an entity that can be spawned by packet 0x18
             */
            enum class Mob : int8_t {
                UNKNOWN = -1,
                CREEPER = 50,
                SKELETON = 51,
                SPIDER = 52,
                GIANT = 53,
                ZOMBIE = 54,
                SLIME = 55,
                GHAST = 56,
                PIGZOMBIE = 57,
                PIG = 90,
                SHEEP = 91,
                COW = 92,
                CHICKEN = 93
            };

            /**
             * Get string representation of a mob
             * @param m Mob to get string representation of
             * @return  String representation of m
             */
            std::string mobName(Mob m);
        }
    }
}

#endif
