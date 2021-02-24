#include <iostream>
#include <mutex>

#include "stde/log/log.hpp"
#include "stde/net/init.hpp"

#include "gpworld/Chunk.hpp"

int main(int argc, char** argv) {
    std::ifstream f("world/0/0/c.0.0.dat");
    gp::world::Chunk c(f);

    std::ofstream o("out.dat");
    c.save(o);
}
