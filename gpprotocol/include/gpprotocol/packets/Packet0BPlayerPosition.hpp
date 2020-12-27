#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET0BPLAYERPOSITION_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET0BPLAYERPOSITION_HPP_

#include "gpprotocol/packets/Packet0APlayer.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Contains position of the client.
             */
            class Packet0BPlayerPosition: public Packet0APlayer {
            public:
                /**
                 * Constructor.
                 */
                Packet0BPlayerPosition() : Packet0APlayer(), x(0), y(0), stance(0), z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet0BPlayerPosition() {

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
                    Packet0APlayer::write(dos);
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "PlayerPos [onground: " << +onground << "; x: " << x << "; y: " << y << "; z: " << z << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x0B;
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
            };

        }
    }
}

#endif
