#ifndef INCLUDE_GPPROTOCOL_TYPES_EXPLOSIONRECORD_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_EXPLOSIONRECORD_HPP_
/** @file **/

#include <cstdint>

namespace gp {
    namespace protocol {
        namespace types {
            /**
             * Contains information about an explosion
             */
            struct ExplosionRecord {
                /**
                 * X offset
                 */
                int8_t x;

                /**
                 * Y offset
                 */
                int8_t y;

                /**
                 * Z offset
                 */
                int8_t z;
            };
        }
    }
}

#endif
