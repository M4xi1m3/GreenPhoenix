#include "gpproxy/ProxyConfig.hpp"

using namespace gp::proxy;

stde::log::log ProxyConfig::l = stde::log::log::get("config");

stde::conf::properties ProxyConfig::properties;
std::string ProxyConfig::ip = "0.0.0.0";
int ProxyConfig::port = 25565;
std::string ProxyConfig::default_server = "default";
std::string ProxyConfig::server_file = "servers.properties";
stde::conf::properties ProxyConfig::server_list;

void ProxyConfig::load(const std::string& file) {
    l << stde::log::level::info << "Loading " << file << std::endl;
    std::ifstream in(file);
    if (in) {
        properties.load(in);

        ip = getStringOrDefault("proxy.ip", "0.0.0.0");
        port = getIntOrDefault("proxy.port", 25565);
        default_server = getStringOrDefault("proxy.default", "default");
        server_file = getStringOrDefault("proxy.servers", "servers.properties");

        std::ifstream serv_in(server_file);
        if (serv_in) {
            server_list.load(serv_in);
        }
    } else {
        save(file);
    }
}

void ProxyConfig::save(const std::string& file) {
    l << stde::log::level::info << "Saving " << file << std::endl;
    std::ofstream out(file);
    if (out) {
        properties["proxy.ip"] = ip;
        properties["proxy.port"] = std::to_string(port);
        properties["proxy.default"] = default_server;
        properties["proxy.servers"] = server_file;

        properties.save(out);

        std::ofstream serv_out(server_file);
        if (serv_out)
            server_list.save(serv_out);
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
