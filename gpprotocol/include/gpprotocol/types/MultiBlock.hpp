#ifndef INCLUDE_GPPROTOCOL_TYPES_MULTIBLOCK_HPP_
#define INCLUDE_GPPROTOCOL_TYPES_MULTIBLOCK_HPP_
/** @file **/

#include <cstdint>

namespace gp {
    namespace protocol {
        namespace types {
            struct MultiBlock {
                /**
                 * X position inside of the chunk
                 */
                uint8_t x;

                /**
                 * Z position inside of the chunk
                 */
                uint8_t z;

                /**
                 * Y position inside of the chunk
                 */
                uint8_t y;

                /**
                 * ID of the new block
                 */
                int8_t type;

                /**
                 * Metadata of the new block
                 */
                int8_t metadata;
            };
        }
    }
}

#endif
