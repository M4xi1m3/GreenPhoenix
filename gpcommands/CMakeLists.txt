cmake_minimum_required(VERSION 3.16)
project(gp-commands)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_library(gpcommands STATIC ${SOURCES})
set(GPCOMMANDS_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add STDE headers
target_include_directories(gpcommands PUBLIC ${STDE_HEADERS})
# Add GPCOMMANDS headers
target_include_directories(gpcommands PUBLIC ${GPCOMMANDS_HEADERS})

find_package(Threads)
# Add libs
target_link_libraries(gpcommands stde ${CMAKE_THREAD_LIBS_INIT})

# Set header path for parent scope.
set(GPCOMMANDS_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

