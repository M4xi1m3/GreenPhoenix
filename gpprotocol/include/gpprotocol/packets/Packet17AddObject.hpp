#ifndef INCLUDE_GPPROTOCOL_PACKETS_PACKET17ADDOBJECT_HPP_
#define INCLUDE_GPPROTOCOL_PACKETS_PACKET17ADDOBJECT_HPP_

#include "gpprotocol/Packet.hpp"
#include "gpprotocol/types/Object.hpp"

namespace gp {
    namespace protocol {
        namespace packets {
            /**
             * @brief Sent by the server when an Object/Vehicle is created.
             */
            class Packet17AddObject: public Packet {
            public:
                /**
                 * Constructor.
                 */
                Packet17AddObject() : eid(0), type(types::Object::UNKNOWN), x(0), y(0), z(0) {

                }

                /**
                 * Destructor
                 */
                virtual ~Packet17AddObject() {

                }

                /**
                 * Reads packet from stream.
                 * @param dis   Input stream.
                 */
                virtual void read(stde::streams::data_istream& dis) {
                    eid = dis.read_int();
                    type = (types::Object) dis.read_byte();
                    x = dis.read_int();
                    y = dis.read_int();
                    z = dis.read_int();
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
                }

                /**
                 * Print an human-readable representation of the packet.
                 * @param out   Output stream to write to.
                 */
                virtual void debug(std::ostream& out) const {
                    out << "AddObject [eid: " << eid << "; type: " << types::objectName(type) << "; x: " << x << "; y: " << y << "; z: " << z << "]";
                }

                /**
                 * Get the ID associated with the packet's class.
                 * @return  Packet ID.
                 */
                constexpr static int getID() {
                    return 0x17;
                }

                /**
                 * EID of the object
                 */
                int32_t eid;

                /**
                 * Type of the object
                 */
                types::Object type;

                /**
                 * Object's X position
                 */
                int32_t x;

                /**
                 * Object's Y position
                 */
                int32_t y;

                /**
                 * Object's Z position
                 */
                int32_t z;
            };

        }
    }
}

#endif
