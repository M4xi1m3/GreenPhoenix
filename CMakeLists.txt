cmake_minimum_required(VERSION 3.16)
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(GreenPhoenix VERSION 1.0.1)

configure_file(gpconfig/Version.hpp.in gpconfig/gpconfig/Version.hpp)
include_directories("${PROJECT_BINARY_DIR}/gpconfig")

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

if(DEFINED ASAN)
    # Avoid getting a warning for unused variable.
    set(ignoreMe ${ASAN})

    message("Building with Address Sanitizer...")
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
endif()

add_subdirectory(external)
add_subdirectory(gpworld)
add_subdirectory(gpnet)
add_subdirectory(gpprotocol)
add_subdirectory(gpcommands)
add_subdirectory(gpproxy)
add_subdirectory(gpbot)
add_subdirectory(gpserver)
add_subdirectory(doc)

