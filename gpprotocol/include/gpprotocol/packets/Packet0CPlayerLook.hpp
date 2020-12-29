#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0CPLAYERLOOK_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0CPLAYERLOOK_HPP_

#include "gpprotocol/packets/Packet0APlayer.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Contains rotation of the client.
             */
            class Packet0CPlayerLook: public Packet0APlayer {
            public:
                /**
                 * Constructor.
                 */
                Packet0CPlayerLook() : Packet0APlayer(), yaw(0), pitch(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0CPlayerLook() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    yaw = dis.read_float();
                    pitch = dis.read_float();
                    Packet0APlayer::read(dis);
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_float(yaw);
                    dos.write_float(pitch);
                    Packet0APlayer::write(dos);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "PlayerLook [onground: " << +onground << "; yaw: " << yaw << "; pitch: " << pitch << "]";
                }

                packetID(0x0C)

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
