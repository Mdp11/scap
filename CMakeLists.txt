cmake_minimum_required(VERSION 3.10)

project(Simple_Command_Line_Audio_Player)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

file(GLOB project_SRCS src/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod/lib/${CMAKE_SYSTEM_PROCESSOR})

add_executable(scap ${project_SRCS})
target_link_libraries(scap libfmod.so)
