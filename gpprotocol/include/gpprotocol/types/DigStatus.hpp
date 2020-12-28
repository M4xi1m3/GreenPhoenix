#ifndef INCLUDE_GPPROTOCOL_TYPES_DIGSTATUS_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_DIGSTATUS_HPP_

#include <cstdint>
#include <string>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Represents a phase in the digging process.
             */
            enum class DigStatus : int8_t {
                UNKNOWN = -1, START = 0, DIG = 1, STOP = 2, BREAK = 3
            };

            /**
             * Gets the string representation of a dig status.
             * @param d DigStatus to get the string representation of.
             * @return  String representation of d.
             */
            std::string digStatusName(DigStatus d);
        }
    }
}

#endif
