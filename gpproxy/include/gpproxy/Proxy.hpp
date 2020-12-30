#ifndef INCLUDE_GPPROXY_PROXY_HPP_
#define INCLUDE_GPPROXY_PROXY_HPP_

#include <gpproxy/ProxyManager.hpp>
#include "gpnet/TCPServer.hpp"


namespace gp {
    namespace proxy {

        class Proxy {
        public:
            virtual ~Proxy();

            void run();

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
            net::TCPServer<ProxyManager>* server = nullptr;

        };

    }
}
#endif
