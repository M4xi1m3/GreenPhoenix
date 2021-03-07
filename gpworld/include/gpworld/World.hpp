#ifndef INCLUDE_GPWORLD_WORLD_HPP_
#define INCLUDE_GPWORLD_WORLD_HPP_

#include <string>
#include <random>
#include "stde/log/log.hpp"

namespace gp {
    namespace world {

        class World {
        public:
            World(const std::string& name);

            bool load();
            void create();
            void save();

            virtual ~World();
        private:
            std::string m_name;
            static stde::log::log l;

            int64_t m_lastPlayed;
            int64_t m_sizeOnDisk;
            int64_t m_randomSeed;
            int32_t m_spawnX;
            int32_t m_spawnY;
            int32_t m_spawnZ;
            int64_t m_time;

        private:
            /* Seed */
            static std::random_device m_rd;

            /* Random number generator */
            static std::default_random_engine m_generator;

            /* Distribution on which to apply the generator */
            static std::uniform_int_distribution<int64_t> m_distribution;

            static inline int64_t random() {
                return m_distribution(m_generator);
            }
        };

    }
}

#endif
