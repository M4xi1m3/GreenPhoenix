cmake_minimum_required(VERSION 3.16)
project(gp-proxy)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_executable(gpbot ${SOURCES})
set(GPBOT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add headers
target_include_directories(gpbot PUBLIC ${STDE_HEADERS})
target_include_directories(gpbot PUBLIC ${GPNET_HEADERS})
target_include_directories(gpbot PUBLIC ${GPPROTOCOL_HEADERS})
target_include_directories(gpbot PUBLIC ${GPCOMMANDS_HEADERS})
target_include_directories(gpbot PUBLIC ${GPBOT_HEADERS})

# Add STDE lib
target_link_libraries(gpbot gpprotocol gpnet gpcommands stde)

# Set header path for parent scope.
set(GPBOT_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

