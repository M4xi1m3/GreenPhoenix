#ifndef INCLUDE_GPPROTOCOL_TYPES_STATUS_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_STATUS_HPP_
/** @file **/

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents an entity status
             */
            enum class Status : int8_t {
                UNKNOWN = -1, DAMAGE = 2, DEATH = 3, PRIMED = 4, NOT_PRIMED = 5
            };

            /**
             * Get string representation of a Status
             * @param s Status to get the representation of
             * @return  String representation of s
             */
            std::string statusName(Status s);
        }
    }
}

#endif
