#ifndef GPSERVER_SRC_TESTHANDLER_HPP_
#define GPSERVER_SRC_TESTHANDLER_HPP_

#include "gpnet/TCPHandler.hpp"

namespace gp {
    namespace server {

        class TestHandler: public gp::net::TCPHandler {
        public:
            TestHandler(stde::net::sock& client_socket, int id) : TCPHandler(client_socket, id) {
            }

            virtual ~TestHandler();

            void handle();
            void stop();
        private:
            bool m_stop = false;
        };

    }
}
#endif
