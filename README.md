# SCAP
SCAP (Simple Command line Audio Player) is a really simple audio player that works from the command line.

It uses the FMOD APIs to handle sounds, which are already included in the project.

## Dependencies for Running Locally
* Linux OS
* cmake >= 3.10
* make >= 4.1
* gcc/g++ >= 5.4
* working audio!

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./scap`

Two samples mp3 files are available in this repo under the "samples" folder.

## Current functionalities

* Add a song to the playlist
* Play/Pause
* Go to the next song in the playlist
* Show currently played song

## Future improvements

* Check all songs currently in the playlist
* Remove/Play a particular song from the playlist
* Activate/Deactivate shuffle
* Specific mp3 support with tag reading
* Raise/Lower volume
* Mute/Unmute
* ncurses based UI

## Udacity rubric points
In the following list only one example addressing each point is indicated, since in most cases there are more of them.

* The project demonstrates an understanding of C++ functions and control structures: any file
* The project reads data from a file and process the data, or the program writes data to a file: music_player.cpp:57
* The project accepts user input and processes the input: main.cpp:18
* The project uses Object Oriented Programming techniques: any class
* Classes use appropriate access specifiers for class members: any class
* Class constructors utilize member initialization lists: io_handler.cpp:8
* Classes abstract implementation details from their interfaces: any class
* Classes encapsulate behavior: any class
* Classes follow an appropriate inheritance hierarchy: actions.hpp
* Derived class functions override virtual base class functions: actions.hpp
* Templates generalize functions in the project: message_queue.hpp:8
* The project makes use of references in function declarations: music_player.hpp:37
* The project uses destructors appropriately: music_player.cpp:40
* The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate: music_player.cpp:16 - music_player.cpp:40
* The project follows the Rule of 5: music_player.hpp:22-26
* The project uses move semantics to move data, instead of copying it, where possible: message_queue.hpp:23
* The project uses smart pointers instead of raw pointers: playlist.hpp:11
* The project uses multithreading: any file
* A promise and future is used in the project: io_handler.cpp:24
* A mutex or lock is used in the project: message_queue.hpp:14
* A condition variable is used in the project: message_queue.hpp:22
