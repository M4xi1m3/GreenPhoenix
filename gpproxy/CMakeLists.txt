cmake_minimum_required(VERSION 3.16)
project(gp-proxy)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_executable(gpproxy ${SOURCES})
set(GPPROXY_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add headers
target_include_directories(gpproxy PUBLIC ${STDE_HEADERS})
target_include_directories(gpproxy PUBLIC ${GPNET_HEADERS})
target_include_directories(gpproxy PUBLIC ${GPPROTOCOL_HEADERS})
target_include_directories(gpproxy PUBLIC ${GPPROXY_HEADERS})

# Add STDE lib
target_link_libraries(gpproxy gpprotocol gpnet stde)

# Set header path for parent scope.
set(GPPROXY_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

