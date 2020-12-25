cmake_minimum_required(VERSION 3.16)

# Add stde
message(WARNING "Downloading stde...")
configure_file(CMakeLists.txt.in stde-download/CMakeLists.txt)

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/stde-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/stde-download"
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stde)
set(STDE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/stde/include)



# Add nbtpp
set(HAS_STDE true)
message(WARNING "Downloading nbtpp...")

execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/nbtpp-download"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/nbtpp-download"
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/nbtpp)

# Set header path for parent scope.
set(STDE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/stde/include PARENT_SCOPE)
set(NBTPP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/nbtpp/include PARENT_SCOPE)

