cmake_minimum_required(VERSION 3.16)


add_subdirectory(external)
add_subdirectory(gpnet)
add_subdirectory(gpserver)



#find_package(Threads)

#target_link_libraries(greenphoenix nbtpp stde ${CMAKE_THREAD_LIBS_INIT})

#target_include_directories(greenphoenix PUBLIC
#    ${STDE_HEADERS}
#    PRIVATE src)

#target_include_directories(greenphoenix PUBLIC
#    ${NBTPP_HEADERS}
#    PRIVATE src)

