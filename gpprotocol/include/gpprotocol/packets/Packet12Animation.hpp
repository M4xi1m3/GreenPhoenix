#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET12ANIMATION_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET12ANIMATION_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Animation.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent whenever an entity should change animation.
             */
            class Packet12Animation: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet12Animation() : eid(0), animation(types::Animation::NONE) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet12Animation() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    animation = (types::Animation) dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_byte((int8_t) animation);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Animation [eid: " << +eid << "; animation: " << types::animationName(animation) << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x12;
                }

                /**
                 * Entity ID
                 */
                int32_t eid;

                /**
                 * Animation to set
                 */
                types::Animation animation;
            };

        }
    }
}

#endif
