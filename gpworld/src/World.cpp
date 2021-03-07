#include "gpworld/World.hpp"

#include <ctime>
#include <fstream>
#include <filesystem>
#include "nbtpp/nbt.hpp"

using namespace gp::world;

stde::log::log World::l = stde::log::log::get("world");
std::random_device World::m_rd;
std::default_random_engine World::m_generator(m_rd());
std::uniform_int_distribution<int64_t> World::m_distribution(0,0xFFFFFFFFFFFFFFFF);

World::World(const std::string& name) : m_name(name) {
    if (!load())
        create();

    save();
}

bool World::load() {
    std::string level_dat = m_name + std::filesystem::path::preferred_separator + "level.dat";

    l << stde::log::level::debug << "Loading " + level_dat << std::endl;

    std::ifstream f(level_dat);
    if (f) {
        nbtpp::nbt tag(f);
        tag.debug();

        nbtpp::tags::tag_compound *root = dynamic_cast<nbtpp::tags::tag_compound*>(tag.content());
        nbtpp::tags::tag_compound *data = dynamic_cast<nbtpp::tags::tag_compound*>(root->get("Data"));

        m_lastPlayed = dynamic_cast<nbtpp::tags::tag_long*>(data->get("LastPlayed"))->value();
        m_sizeOnDisk = dynamic_cast<nbtpp::tags::tag_long*>(data->get("SizeOnDisk"))->value();
        m_randomSeed = dynamic_cast<nbtpp::tags::tag_long*>(data->get("RandomSeed"))->value();

        m_spawnX = dynamic_cast<nbtpp::tags::tag_int*>(data->get("SpawnX"))->value();
        m_spawnY = dynamic_cast<nbtpp::tags::tag_int*>(data->get("SpawnY"))->value();
        m_spawnZ = dynamic_cast<nbtpp::tags::tag_int*>(data->get("SpawnZ"))->value();

        m_time = dynamic_cast<nbtpp::tags::tag_long*>(data->get("Time"))->value();

        return true;
    } else {
        return false;
    }
}

void World::create() {
    // TODO: Don't assume the system uses UNIX time
    m_lastPlayed = std::time(nullptr);
    m_sizeOnDisk = 0;
    m_randomSeed = random();

    m_spawnX = 0;
    m_spawnY = 64;
    m_spawnZ = 0;

    m_time = 0;
}

void World::save() {
    if (std::filesystem::exists(m_name)) {
        if (!std::filesystem::is_directory(m_name)) {
            throw new std::runtime_error("World " + m_name + " exists but is not a directory!");
        }
    } else {
        if (!std::filesystem::create_directory(m_name)) {
            throw new std::runtime_error("World directory " + m_name + " cannot be created!");
        }
    }

    std::string level_dat = m_name + std::filesystem::path::preferred_separator + "level.dat";

    l << stde::log::level::debug << "Saving " + level_dat << std::endl;

    nbtpp::tags::tag_compound* root = new nbtpp::tags::tag_compound("");
    nbtpp::tags::tag_compound* data = new nbtpp::tags::tag_compound("Data");
    data->insert(new nbtpp::tags::tag_long("LastPlayed", m_lastPlayed));
    data->insert(new nbtpp::tags::tag_long("SizeOnDisk", m_sizeOnDisk));
    data->insert(new nbtpp::tags::tag_long("RandomSeed", m_randomSeed));

    data->insert(new nbtpp::tags::tag_int("SpawnX", m_spawnX));
    data->insert(new nbtpp::tags::tag_int("SpawnY", m_spawnY));
    data->insert(new nbtpp::tags::tag_int("SpawnZ", m_spawnZ));

    data->insert(new nbtpp::tags::tag_long("Time", m_time));
    root->insert(data);
    nbtpp::nbt level(root);
    level.debug();

    std::ofstream f(level_dat);
    level.save(f);
}

World::~World() {
    // TODO Auto-generated destructor stub
}
