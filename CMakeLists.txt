cmake_minimum_required(VERSION 3.15)
project(Algoritmos)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE FONTES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")

foreach(fonte ${FONTES})
    if(fonte MATCHES "cmake-build")
        continue()
    endif()
    get_filename_component(nome ${fonte} NAME_WE)
    string(REPLACE " " "_" nome ${nome})
    add_executable(${nome} ${fonte})
endforeach()