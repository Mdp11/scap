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

* Add songs by folder
* Advanced playlist manipulation (move songs up/down, shuffle)
* Show advandaced info about songs (tags reading)
* Volume manipulation
* ncurses based UI
