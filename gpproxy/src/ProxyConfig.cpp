#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy;

stde::conf::properties ProxyConfig::properties;

void ProxyConfig::load(const std::string& file) {
    std::ifstream in(file);
    if (in) {
        properties.load(in);
    }
}

void ProxyConfig::save(const std::string& file) {
    std::ofstream out(file);
    if (out) {
        properties.save(out);
    }
}

std::string ProxyConfig::getStringOrDefault(std::string key, std::string def) {
    try {
        return properties.at(key);
    } catch (std::out_of_range &e) {
        properties[key] = def;
    }

    return def;
}

int ProxyConfig::getIntOrDefault(std::string key, int def) {
    try {
        return std::stoi(properties.at(key));
    } catch (std::out_of_range &e) {
        properties[key] = std::to_string(def);
    }

    return def;
}
