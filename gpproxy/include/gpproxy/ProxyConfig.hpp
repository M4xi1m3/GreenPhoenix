#ifndef INCLUDE_GPPROXY_PROXYCONFIG_HPP_
#define INCLUDE_GPPROXY_PROXYCONFIG_HPP_

#include "stde/conf/properties.hpp"
#include <fstream>
#include <exception>

namespace gp {
    namespace proxy {

        class ProxyConfig {
        public:
            ProxyConfig() = delete;
            virtual ~ProxyConfig() = delete;

            static void load(const std::string& file);

            static void save(const std::string& file);

            static std::string getStringOrDefault(std::string key, std::string def);

            static int getIntOrDefault(std::string key, int def);
        private:
            static stde::conf::properties properties;
        };

    }
}
#endif
