#ifndef INCLUDE_GPPROTOCOL_TYPES_MULTIBLOCK_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_MULTIBLOCK_HPP_

#include <cstdint>

namespace gp {
    namespace protocol {
        namespace types {
            struct MultiBlock {
                uint8_t x;
                uint8_t z;
                uint8_t y;
                int8_t type;
                int8_t metadata;
            };
        }
    }
}

#endif
