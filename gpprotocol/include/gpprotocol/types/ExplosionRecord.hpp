#ifndef INCLUDE_GPPROTOCOL_TYPES_EXPLOSIONRECORD_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_EXPLOSIONRECORD_HPP_

#include <cstdint>

namespace gp {
    namespace protocol {
        namespace types {
            struct ExplosionRecord {
                int8_t x;
                int8_t y;
                int8_t z;
            };
        }
    }
}

#endif
