#ifndef INCLUDE_GPPROTOCOL_TYPES_STATUS_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_STATUS_HPP_

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents an entity status
             */
            enum class Status : int8_t {
                UNKNOWN = -1, UNK2 = 2, UNK3 = 3, UNK4 = 4, UNK5 = 5
            };

            /**
             * Get string representation of a Status
             * @param s Status to get the representation of
             * @return  String representation of s
             */
            std::string statusnName(Status a);
        }
    }
}

#endif
