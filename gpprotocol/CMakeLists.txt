cmake_minimum_required(VERSION 3.16)
project(gp-protocol)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_library(gpprotocol STATIC ${SOURCES})
set(GPPROTOCOL_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add STDE headers
target_include_directories(gpprotocol PUBLIC ${STDE_HEADERS})
# Add GPNET headers
target_include_directories(gpprotocol PUBLIC ${GPNET_HEADERS})
# Add GPPROTOCOL headers
target_include_directories(gpprotocol PUBLIC ${GPPROTOCOL_HEADERS})

find_package(Threads)
# Add libs
target_link_libraries(gpprotocol stde ${CMAKE_THREAD_LIBS_INIT})

# Set header path for parent scope.
set(GPPROTOCOL_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

