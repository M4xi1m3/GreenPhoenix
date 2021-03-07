#include "gpworld/Chunk.hpp"

#include "nbtpp/tag.hpp"

#include <cstring>

using namespace gp::world;

Chunk::Chunk(std::ifstream& file) {
    load(file);
}

/**
 * Unpacks a 4-bits-per-value array in a 8-bits-per-value one
 *
 * @param in    Input array (4BPV)
 * @param out   Output array (8BPV)
 * @param count Number of elements. Must be a multiple of two.
 * @return  out
 */
static inline int8_t* unpack_four(const int8_t* in, int8_t* out, size_t count) {

    for (int i = 0; i < (count / 2); i++) {
        out[i * 2] = (in[i] >> 4) & 0x0F;
        out[i * 2 + 1] = in[i] & 0x0F;
    }

    return out;
}

/**
 * Packs a 8-bits-per-value array in a 4-bits-per-values one
 *
 * @param in    Input array (8BPV)
 * @param out   Output array (4BPV)
 * @param count Number of elements. Must be a multiple of two.
 * @return  out
 */
static inline int8_t* pack_four(const int8_t* in, int8_t* out, size_t count) {

    for (int i = 0; i < (count / 2); i++) {
        out[i] = ((in[i * 2] & 0x0F) << 4) | (in[i * 2 + 1] & 0x0F);
    }

    return out;
}

void Chunk::load(std::ifstream& file) {
    m_tag.load_file(file);
    m_tag.debug();

    nbtpp::tags::tag_compound *root = dynamic_cast<nbtpp::tags::tag_compound*>(m_tag.content());

    nbtpp::tags::tag_compound *level = dynamic_cast<nbtpp::tags::tag_compound*>(root->get("Level"));

    m_x = dynamic_cast<nbtpp::tags::tag_int*>(level->get("xPos"))->value();
    m_z = dynamic_cast<nbtpp::tags::tag_int*>(level->get("zPos"))->value();

    m_populated = dynamic_cast<nbtpp::tags::tag_byte*>(level->get("TerrainPopulated"))->value();

    m_lastupdate = dynamic_cast<nbtpp::tags::tag_long*>(level->get("LastUpdate"))->value();

    memcpy(m_block, dynamic_cast<nbtpp::tags::tag_bytearray*>(level->get("Blocks"))->value().data(), 32768);

    unpack_four(dynamic_cast<nbtpp::tags::tag_bytearray*>(level->get("Data"))->value().data(), m_data, 32768);
    unpack_four(dynamic_cast<nbtpp::tags::tag_bytearray*>(level->get("BlockLight"))->value().data(), m_block_light, 32768);
    unpack_four(dynamic_cast<nbtpp::tags::tag_bytearray*>(level->get("SkyLight"))->value().data(), m_sky_light, 32768);

    memcpy(m_height_map, dynamic_cast<nbtpp::tags::tag_bytearray*>(level->get("HeightMap"))->value().data(), 256);

}

void Chunk::save(std::ofstream& file) {
    int8_t tmp[16384];

    nbtpp::tags::tag_compound *root = new nbtpp::tags::tag_compound("");
    nbtpp::tags::tag_compound *level = new nbtpp::tags::tag_compound("Level");

    level->insert(new nbtpp::tags::tag_int("xPos", m_x));
    level->insert(new nbtpp::tags::tag_int("zPos", m_z));

    level->insert(new nbtpp::tags::tag_byte("TerrainPopulated", m_populated));

    level->insert(new nbtpp::tags::tag_long("LastUpdate", m_lastupdate));

    level->insert(new nbtpp::tags::tag_bytearray("Blocks", std::vector<int8_t>(m_block, m_block + 32768)));

    level->insert(new nbtpp::tags::tag_bytearray("Data", std::vector<int8_t>(pack_four(m_data, tmp, 32768), tmp + 16384)));
    level->insert(new nbtpp::tags::tag_bytearray("BlockLight", std::vector<int8_t>(pack_four(m_block_light, tmp, 32768), tmp + 16384)));
    level->insert(new nbtpp::tags::tag_bytearray("SkyLight", std::vector<int8_t>(pack_four(m_sky_light, tmp, 32768), tmp + 16384)));

    level->insert(new nbtpp::tags::tag_bytearray("HeightMap", std::vector<int8_t>(m_height_map, m_height_map + 256)));

    root->insert(level);
    nbtpp::nbt nbt(root);
    nbt.debug();
    nbt.save(file);
}

Chunk::~Chunk() {

}
