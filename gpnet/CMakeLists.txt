cmake_minimum_required(VERSION 3.16)
project(gp-net)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_library(gpnet STATIC ${SOURCES})
set(GPNET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add STDE headers
target_include_directories(gpnet PUBLIC ${STDE_HEADERS})
# Add GPNET headers
target_include_directories(gpnet PUBLIC ${GPNET_HEADERS})

# Add STDE lib
target_link_libraries(gpnet stde)

# Set header path for parent scope.
set(GPNET_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

