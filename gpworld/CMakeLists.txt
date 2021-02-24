cmake_minimum_required(VERSION 3.16)
project(gp-world)

# Grab all sources
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Create static target
add_library(gpworld STATIC ${SOURCES})
set(GPWORLD_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add STDE headers
target_include_directories(gpworld PUBLIC ${STDE_HEADERS})
# Add NBTPP headers
target_include_directories(gpworld PUBLIC ${NBTPP_HEADERS})
# Add gpworld headers
target_include_directories(gpworld PUBLIC ${GPWORLD_HEADERS})

find_package(Threads)
# Add libs
target_link_libraries(gpworld stde nbtpp ${CMAKE_THREAD_LIBS_INIT})

# Set header path for parent scope.
set(GPWORLD_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

