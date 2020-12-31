#ifndef INCLUDE_GPPROXY_PROXYCONFIG_HPP_
#define INCLUDE_GPPROXY_PROXYCONFIG_HPP_

#include "stde/conf/properties.hpp"
#include "stde/log/log.hpp"
#include <fstream>
#include <exception>

namespace gp {
    namespace proxy {

        /**
         * Handles configuration of the proxy.
         */
        class ProxyConfig {
        public:
            ProxyConfig() = delete;
            virtual ~ProxyConfig() = delete;

            /**
             * Load configuration from file
             * @param file  File name to load from
             */
            static void load(const std::string& file);

            /**
             * Save configuration to file
             * @param file  File name to save to
             */
            static void save(const std::string& file);

            /**
             * Proxy's IP address
             */
            static std::string ip;

            /**
             * Proxy's port
             */
            static int port;

            /**
             * Name of the default server
             */
            static std::string default_server;

            /**
             * File to load server list from
             */
            static std::string server_file;

            /**
             * List of servers.
             */
            static stde::conf::properties server_list;
        private:

            /**
             * Get string or default value
             * @param key
             * @param def
             * @return
             */
            static std::string getStringOrDefault(std::string key, std::string def);

            /**
             * Get int or default value
             * @param key
             * @param def
             * @return
             */
            static int getIntOrDefault(std::string key, int def);

            static stde::conf::properties properties;

            static stde::log::log l;
        };

    }
}
#endif
