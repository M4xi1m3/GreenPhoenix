#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET01LOGIN_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET01LOGIN_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Second packet sent by the client, used to send data (name, seed, ...).
             */
            class Packet01Login: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet01Login() : version(0), username(""), password(""), seed(0L), dimmension(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet01Login() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    version = dis.read_int();
                    username = dis.read_string();
                    password = dis.read_string();
                    seed = dis.read_long();
                    dimmension = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(version);
                    dos.write_string(username);
                    dos.write_string(password);
                    dos.write_long(seed);
                    dos.write_byte(dimmension);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Login [username: " << username << "; password: " << password << "; seed" << +seed << "; dimmension: " << +dimmension << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x01;
                }

                /**
                 * Protocol version
                 */
                int version;

                /**
                 * Username
                 */
                std::string username;

                /**
                 * Password
                 */
                std::string password;

                /**
                 * Seed of the world
                 */
                int64_t seed;

                /**
                 * Dimmension
                 */
                int8_t dimmension;
            };

        }
    }
}

#endif
