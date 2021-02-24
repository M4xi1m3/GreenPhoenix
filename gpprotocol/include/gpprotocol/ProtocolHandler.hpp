#ifndef INCLUDE_PROTOCOLHANDLER_HPP_
#define INCLUDE_PROTOCOLHANDLER_HPP_

#include "gpnet/TCPHandler.hpp"

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/PacketHander.hpp"

#include "stde/log/log.hpp"
#include "stde/streams/exceptions.hpp"

namespace gp {
    namespace protocol {
        /**
         * Handles A1.2.6 protocol
         */
        template<class T, typename = std::enable_if<std::is_base_of<PacketHandler, T>::value>>
        class ProtocolHandler: public gp::net::TCPHandler {
        public:
            /**
             * Constructor
             * @param client_socket Socket of the client
             * @param id    Unique TCPHandler id
             */
            ProtocolHandler(stde::net::sock& client_socket, int id) : TCPHandler(client_socket, id), m_dis(m_is, stde::streams::endianconv::big), m_dos(m_os,
                    stde::streams::endianconv::big), l(stde::log::log::get("protocol")) {
                handler.init(id, &m_socket, &m_dos);
            }

            /**
             * Destructor
             */
            virtual ~ProtocolHandler() {

            }

            /**
             * Handle the connection
             */
            void handle() {
                handler.started();
                while (!mustStop()) {
                    try {
                        Packet *p = Packet::parse(m_dis);
                        handler.handle(p);

                        delete p;

                    } catch (stde::streams::eof_exception &e) {
                        break;
                    } catch (std::exception &e) {
                        l << stde::log::level::error << e.what() << std::endl;
                        break;
                    }
                }
                handler.closed();
                m_socket.close();
            }

            /**
             * Stop the hander
             */
            void stop() {
                if (!done())
                    handler.stop();
                m_socket.shutdown();
                m_socket.close();
            }

            /**
             * Get pointer to handler
             * @return  Pointer to handler
             */
            T* getHandler() {
                return &handler;
            }
        private:
            stde::log::log l;

            stde::streams::data_istream m_dis;
            stde::streams::data_ostream m_dos;

            T handler;
        };

    }
}
#endif
