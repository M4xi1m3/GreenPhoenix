#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET07USEENTITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET07USEENTITY_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet indicated the client interacted with an entity, either by right-clicking or left-clicking.
             */
            class Packet07UseEntity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet07UseEntity() : user(0), target(0), attack(false) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet07UseEntity() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    user = dis.read_int();
                    target = dis.read_int();
                    attack = dis.read_bool();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {

                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "UseEntity [user: " << user << "; target: " << target << "; attack: " << +attack << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x07;
                }

                /**
                 * EID of the sender.
                 */
                int32_t user;

                /**
                 * EID of the target.
                 */
                int32_t target;

                /**
                 * True if left click, false otherwise.
                 */
                bool attack;
            };

        }
    }
}

#endif
