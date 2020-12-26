cmake_minimum_required(VERSION 3.16)
set (CMAKE_CXX_STANDARD 11)

project(GreenPhoenix)

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
add_subdirectory(gpnet)
add_subdirectory(gpserver)
add_subdirectory(doc)

