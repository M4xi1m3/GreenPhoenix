#ifndef INCLUDE_GPPROXY_PROXY_HPP_
#define INCLUDE_GPPROXY_PROXY_HPP_

#include <gpproxy/ProxyHandler.hpp>
#include "gpnet/TCPServer.hpp"
#include "gpcommands/Console.hpp"


namespace gp {
    namespace proxy {

        /**
         * GreenPhornix's Proxy. Singleton.
         */
        class Proxy {
        public:
            /**
             * Destructor
             */
            virtual ~Proxy();

            /**
             * Starts the proxy.
             */
            void run();

            /**
             * Stops the proxy.
             */
            void stop();

            /**
             * Get instance.
             * @return  Instance of the proxy.
             */
            static Proxy& getInstance() {
                static Proxy instance;
                return instance;
            }
            Proxy(Proxy const&) = delete;
            void operator=(Proxy const&) = delete;
        private:
            Proxy();
            net::TCPServer<ProxyHandler>* server = nullptr;
            gp::commands::Console console;

        };

    }
}
#endif
