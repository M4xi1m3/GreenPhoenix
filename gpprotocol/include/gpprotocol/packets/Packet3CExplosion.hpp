#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET3CEXPLOSION_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET3CEXPLOSION_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/ExplosionRecord.hpp"
#include <vector>

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief This packet may be sent by the client to keep the connection alive.
             */
            class Packet3CExplosion: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet3CExplosion() : x(0), y(0), z(0), radius(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet3CExplosion() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    x = dis.read_double();
                    y = dis.read_double();
                    z = dis.read_double();
                    radius = dis.read_float();
                    int32_t count = dis.read_int();

                    records.clear();
                    records.resize(count);

                    for (int i = 0; i < count; i++) {
                        records[i].x = dis.read_byte();
                        records[i].y = dis.read_byte();
                        records[i].z = dis.read_byte();
                    }
                }

                /**
                 * Write packet to stream.
                 * @param dos   Output stream.
                 */
                virtual void write(stde::streams::data_ostream& dos) const {
                    dos.write_double(x);
                    dos.write_double(y);
                    dos.write_double(z);
                    dos.write_float(radius);
                    dos.write_int(records.size());
                    for (int i = 0; i < records.size(); i++) {
                        dos.write_byte(records[i].x);
                        dos.write_byte(records[i].y);
                        dos.write_byte(records[i].z);
                    }
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "Explosion [x: " << x << "; y: " << y << "; z: " << z << "; radius: " << radius << "; records: " << records.size() << " records]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x3C;
                }

                double x;
                double y;
                double z;
                float radius;
                std::vector<types::ExplosionRecord> records;
            }
            ;

        }
    }
}

#endif
