#ifndef INCLUDE_GPPROTOCOL_PACKETHANDER_HPP_
#define INCLUDE_GPPROTOCOL_PACKETHANDER_HPP_

#include "gpprotocol/ProtocolHandler.hpp"
#include "stde/log/log.hpp"
#include <iostream>

namespace gp {
    namespace protocol {
        class PacketHandler {
        public:
            PacketHandler() : id(0), m_sock(nullptr), m_dos(nullptr), l(stde::log::log::get("protocol")) {

            }

            virtual ~PacketHandler() {
            }

            /**
             * Send a packet to the connected client
             * @param p Packet to send
             */
            void send(const Packet& p) {
                m_dos->write_byte(p.id());
                p.write(*m_dos);
                m_dos->flush();
            }

            /**
             * Send a packet to the connected client
             * @param p Packet to send
             */
            void send(const Packet* p) {
                m_dos->write_byte(p->id());
                p->write(*m_dos);
                m_dos->flush();
            }

            /**
             * Get id of handler
             * @return  Handler's ID
             */
            int getID() {
                return id;
            }

            /**
             * Close connection with the client.
             */
            void close() {
                m_sock->shutdown();
                m_sock->close();
            }

            /**
             * Handle packet
             * @param packet    Packet to handle
             */
            virtual void handle(Packet* packet) = 0;

            /**
             * Called when server is stopping.
             */
            virtual void stop() = 0;
        protected:
            /**
             * Logger
             */
            stde::log::log l;
        private:
            int id;
            stde::net::sock *m_sock;
            stde::streams::data_ostream *m_dos;

            void init(int xid, stde::net::sock* sock, stde::streams::data_ostream* dos) {
                id = xid;
                m_sock = sock;
                m_dos = dos;
            }

            template<typename, typename> friend class ProtocolHandler;
        };
    }
}

#endif
