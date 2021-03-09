#include "gpworld/World.hpp"

#include <ctime>
#include <fstream>
#include <filesystem>
#include "nbtpp/nbt.hpp"

using namespace gp::world;

stde::log::log World::l = stde::log::log::get("world");
std::random_device World::m_rd;
std::default_random_engine World::m_generator(m_rd());
std::uniform_int_distribution<uint64_t> World::m_distribution(0,0xFFFFFFFFFFFFFFFF);

World::World(const std::string& name) : m_name(name) {
    if (!load())
        create();

    save();
}

bool World::load() {
    std::string level_dat = m_name + "/level.dat";

    l << stde::log::level::debug << "Loading " + level_dat << std::endl;

    std::ifstream f(level_dat);
    if (f) {
        nbtpp::nbt tag(f);
        tag.debug();

        nbtpp::tags::tag_compound *root = tag.content<nbtpp::tags::tag_compound>();

        // nbtpp::tags::tag_compound *root = dynamic_cast<nbtpp::tags::tag_compound*>(tag.content());
        nbtpp::tags::tag_compound *data = root->get<nbtpp::tags::tag_compound>("Data");

        m_lastPlayed = data->get<nbtpp::tags::tag_long>("LastPlayed")->value();
        m_sizeOnDisk = data->get<nbtpp::tags::tag_long>("SizeOnDisk")->value();
        m_randomSeed = data->get<nbtpp::tags::tag_long>("RandomSeed")->value();

        m_spawnX = data->get<nbtpp::tags::tag_int>("SpawnX")->value();
        m_spawnY = data->get<nbtpp::tags::tag_int>("SpawnY")->value();
        m_spawnZ = data->get<nbtpp::tags::tag_int>("SpawnZ")->value();

        m_time = data->get<nbtpp::tags::tag_long>("Time")->value();

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

    std::string level_dat = m_name + "/level.dat";

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
