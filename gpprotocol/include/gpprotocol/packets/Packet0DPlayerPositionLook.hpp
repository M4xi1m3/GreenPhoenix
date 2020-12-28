#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0DPLAYERPOSITIONLOOK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0DPLAYERPOSITIONLOOK_HPP_

#include "gpprotocol/packets/Packet0APlayer.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Contains position and rotation of the client.
             */
            class Packet0DPlayerPositionLook: public Packet0APlayer {
            public:
                /**
                 * Constructor.
                 */
                Packet0DPlayerPositionLook() : Packet0APlayer(), x(0), y(0), stance(0), z(0), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0DPlayerPositionLook() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_double();
                    y = dis.read_double();
                    stance = dis.read_double();
                    z = dis.read_double();
                    yaw = dis.read_float();
                    pitch = dis.read_float();
                    Packet0APlayer::read(dis);
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_double(x);
                    dos.write_double(y);
                    dos.write_double(stance);
                    dos.write_double(z);
                    dos.write_float(yaw);
                    dos.write_float(pitch);
                    Packet0APlayer::write(dos);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "PlayerPositionLook [onground: " << +onground << "; x: " << x << "; y: " << y << "; z: " << z << "; yaw: " << yaw << "; pitch: "
                            << pitch << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x0D;
                }

                /**
                 * Position X.
                 */
                double x;

                /**
                 * Position Y (feet).
                 */
                double y;

                /**
                 * Top of the bounding box of the player.
                 */
                double stance;

                /**
                 * Position Z.
                 */
                double z;

                /**
                 * Rotation around the X axis
                 */
                float yaw;

                /**
                 * Rotation around the Y axis.
                 */
                float pitch;
            };

        }
    }
}

#endif
