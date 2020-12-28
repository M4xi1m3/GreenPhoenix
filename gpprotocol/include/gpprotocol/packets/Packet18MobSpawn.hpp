#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET08MOBSPAWN_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET08MOBSPAWN_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Mob.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the server when a Mob is spawned.
             */
            class Packet18MobSpawn: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet18MobSpawn() : eid(0), type(types::Mob::UNKNOWN), x(0), y(0), z(0), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet18MobSpawn() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    type = (types::Mob) dis.read_byte();
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_byte((int8_t) type);
                    dos.write_int(x);
                    dos.write_int(y);
                    dos.write_int(z);
                    dos.write_byte(yaw);
                    dos.write_byte(pitch);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "MobSpawn [eid: " << eid << "; type: " << types::mobName(type) << "; x: " << x << "; y: " << y << "; z: " << z << "; yaw: " << yaw
                            << "; pitch: " << pitch << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x18;
                }

                /**
                 * Entity ID
                 */
                int32_t eid;

                /**
                 * Mob to spawn
                 */
                types::Mob type;

                /**
                 * Mob's X position
                 */
                int32_t x;

                /**
                 * Mob's Y position
                 */
                int32_t y;

                /**
                 * Mob's Z position
                 */
                int32_t z;

                /**
                 * Mob's rotation around the X axis
                 */
                int8_t yaw;

                /**
                 * Mob's rotation around the Y axis
                 */
                int8_t pitch;
            };

        }
    }
}

#endif
