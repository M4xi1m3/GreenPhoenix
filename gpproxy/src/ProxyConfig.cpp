#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy;

stde::conf::properties ProxyConfig::properties;
std::string ProxyConfig::ip = "0.0.0.0";
int ProxyConfig::port = 25565;

void ProxyConfig::load(const std::string& file) {
    std::ifstream in(file);
    if (in) {
        properties.load(in);

        ip = getStringOrDefault("proxy.ip", "0.0.0.0");
        port = getIntOrDefault("proxy.port", 25565);
    } else {
        save(file);
    }
}

void ProxyConfig::save(const std::string& file) {
    std::ofstream out(file);
    if (out) {
        properties["proxy.ip"] = ip;
        properties["proxy.port"] = std::to_string(port);

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
