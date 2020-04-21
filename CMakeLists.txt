cmake_minimum_required(VERSION 3.10)

# set(CMAKE_CXX_STANDARD 17)
project(Command_Line_Audio_Player)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")


# Find all executables]]
file(GLOB project_SRCS src/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod/lib/x86_64)

# Add project executable
add_executable(cmd_audio_player ${project_SRCS})
target_link_libraries(cmd_audio_player libfmod.so)
