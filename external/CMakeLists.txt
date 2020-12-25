cmake_minimum_required(VERSION 3.16)
project(external)

# Add stde
message(WARNING "Downloading stde...")
configure_file(CMakeLists.txt.in ${CMAKE_CURRENT_BINARY_DIR}/download/CMakeLists.txt)

message(WARNING ${CMAKE_CURRENT_BINARY_DIR})

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/download"
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stde)
set(STDE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/stde/include)



# Add nbtpp
set(HAS_STDE true)
message(WARNING "Downloading nbtpp...")

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/download"
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/nbtpp)

# Set header path for parent scope.
set(STDE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/stde/include PARENT_SCOPE)
set(NBTPP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/nbtpp/include PARENT_SCOPE)

