cmake_minimum_required(VERSION 3.16)
project(gp-server)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_executable(gpserver ${SOURCES})
set(GPSERVER_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add headers
target_include_directories(gpserver PUBLIC ${STDE_HEADERS})
target_include_directories(gpserver PUBLIC ${GPNET_HEADERS})
target_include_directories(gpserver PUBLIC ${GPSERVER_HEADERS})

# Add STDE lib
target_link_libraries(gpserver gpnet stde)

# Set header path for parent scope.
set(GPSERVER_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

