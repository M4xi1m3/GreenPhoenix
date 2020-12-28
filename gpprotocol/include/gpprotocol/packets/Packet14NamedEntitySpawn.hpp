#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET14NAMEDENTITYSPAWN_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET14NAMEDENTITYSPAWN_HPP_

#include "gpprotocol/Packet.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Send to the client when a player enters range (to spawn it).
             */
            class Packet14NamedEntitySpawn: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet14NamedEntitySpawn() : eid(0), name(""), x(0), y(0), z(0), yaw(0), pitch(0), item_id(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet14NamedEntitySpawn() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    name = dis.read_string();
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
                    yaw = dis.read_byte();
                    pitch = dis.read_byte();
                    item_id = dis.read_short();
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_int(eid);
                    dos.write_string(name);
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
                    out << "NamedEntitySpawn [eid :" << eid << "; name: " << name << "; x: " << x << "; y: " << y << "; z: " << z << "; yaw: " << yaw
                            << "; pitch: " << pitch << "; item: " << item_id << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x14;
                }

                /**
                 * Player's EID
                 */
                int32_t eid;

                /**
                 * Player's name
                 */
                std::string name;

                /**
                 * Player's X position
                 */
                int32_t x;

                /**
                 * Player's Y position
                 */
                int32_t y;

                /**
                 * Player's Z position
                 */
                int32_t z;

                /**
                 * Player's rotation around the X axis
                 */
                int8_t yaw;

                /**
                 * Player's rotation around the Y axis
                 */
                int8_t pitch;

                /**
                 * ID of the item the player is holding
                 */
                int16_t item_id;
            };

        }
    }
}

#endif
