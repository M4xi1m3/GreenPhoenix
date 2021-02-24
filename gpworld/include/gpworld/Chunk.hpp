#ifndef INCLUDE_GPWORLD_CHUNK_HPP_
#define INCLUDE_GPWORLD_CHUNK_HPP_

#include <fstream>

#include "nbtpp/nbt.hpp"

namespace gp {
    namespace world {

        class Chunk {
        public:
            Chunk(std::ifstream& file);

            void load(std::ifstream& file);
            void save(std::ofstream& file);

            virtual ~Chunk();

        private:
            nbtpp::nbt m_tag;

            int m_x, m_z;
            bool m_populated;

            long m_lastupdate;

            int8_t m_block[32768];
            int8_t m_data[32768];
            int8_t m_block_light[32768];
            int8_t m_sky_light[32768];

            int8_t m_height_map[256];
        };

    }
}

#endif
