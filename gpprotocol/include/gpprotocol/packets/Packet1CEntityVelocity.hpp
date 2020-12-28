#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET1CENTITYVELOCITY_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET1CENTITYVELOCITY_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Contains velocity of an entity
             *
             * Velocity is delivered as block velocity * 32000, per tick 200ms
             */
            class Packet1CEntityVelocity: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet1CEntityVelocity() : eid(0), speed_x(0), speed_y(0), speed_z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet1CEntityVelocity() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    speed_x = dis.read_short();
                    speed_y = dis.read_short();
                    speed_z = dis.read_short();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_short(speed_x);
                    dos.write_short(speed_x);
                    dos.write_short(speed_z);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "EntityVelocity [eid: " << eid << "; Vx: " << +speed_x << "; Vy: " << +speed_y << "; Vz: " << +speed_z << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x1C;
                }

                /**
                 * Entity ID
                 */
                int32_t eid;

                /**
                 * Speed of the X axis
                 */
                int16_t speed_x;

                /**
                 * Speed of the Y axis
                 */
                int16_t speed_y;

                /**
                 * Speed of the Z axis
                 */
                int16_t speed_z;
            };

        }
    }
}

#endif
