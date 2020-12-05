# AoC20


[![About](https://img.shields.io/badge/Advent%20of%20Code-2020-brightgreen)](https://adventofcode.com/2019/about)
[![Days completed](https://img.shields.io/badge/Days%20completed-4-red)](https://github.com/dejakobniklas/AdventOfCode/)
[![Stars](https://img.shields.io/badge/Stars-8-yellow)](https://github.com/dejakobniklas/AdventOfCode/)
[![Language: C++](https://img.shields.io/badge/Language-CPP-blue.svg)](https://en.m.wikipedia.org/wiki/C%2B%2B)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://mit-license.org/)

LeMoonStar's Advent of Code 2020 solutions

## Building and compiling
### Linux (Unix Makefiles)
#### Requirements
+ [git](https://git-scm.com/download/linux)
+ [CMake](https://cmake.org/)
+ [gnu make](https://www.gnu.org/software/make/)
+ a compiler of your choise (only tested with GCC and CLang)

#### Building
+ Open a new Terminal
+ Navigate to the directory you want the AoC20 project placed
+ Type (or copy and paste)
  ```bash
  git clone https://github.com/LeMoonStar/AoC20
  cd AoC20
  mkdir build && cd build
  cmake .. -G "Unix Makefiles"
  ```
  this will clone the project and create all required makefiles.
+ Type (or copy and paste)
  ```bash
  make
  ```
  to compile and link the executable.
+ Type (or copy and paste)
  ```bash
  cd ../bin
  ```
  to move to the folder the Executable is placed in.
+ To then execute the executable type `./AoC20`, if everything worked correctly you should now be able to use it.
### Windows (MinGW)
#### Required programs
+ [git](https://git-scm.com/download/win)
+ [CMake's binary distribution](https://cmake.org/download/). Select the radio button that says "Add CMake to the system PATH" either for all users or for the current user or [add it to PATH](https://helpdeskgeek.com/windows-10/add-windows-path-environment-variable/) if you have already installed it
+ [MinGW](https://osdn.net/projects/mingw/releases/). [Add the bin folder (Default: C:\MinGW\bin) to PATH](https://helpdeskgeek.com/windows-10/add-windows-path-environment-variable/) and open the MinGW Installation Manager. Install `mingw32-base-bin` and `mingw32-gcc-g++-bin` by right clicking on the entries and selecting "Mark for Installation". Afterwards, click on Installation (Alt + I) and Apply Changes (A). Wait for the downloads to be finished

#### Building
+ Open a new Terminal (cmd, not PowerShell) by typing in cmd in the Windows search or pressing `Windows + R`, typing in `cmd` and pressing enter
+ Navigate to a directory of your choice where you want to download the source code by typing in `cd path` where `path` can be choosen freely (example: `cd C:\USERNAME\Documents`) and press enter afterwards. (Sidenote: If the directory is not on your main drive (By default: `C:`), you have to type in the drive letter followed by a colon (Example: `D:`) and enter)
+ Type (or copy and paste)
  ```bat
  git clone https://github.com/LeMoonStar/AoC20
  cd AoC20
  mkdir build
  cd build
  cmake .. -G "MinGW Makefiles"
  ```
  and press enter
+ Type (or copy and paste)
  ```bat
  mingw32-make
  ```
  and press enter
+ Type (or copy and paste)
  ```bat
  cd ../bin
  ```
  followed by enter
+ Enter `AoC2020.exe` to start the program

## Check out the AoC2020 solutions of some other people
+ Andi's [aoc2020](https://github.com/andi-makes/aoc2020)
+ derNiklaa's [AoC-2020](https://github.com/derNiklaas/AoC-2020)
+ NetworkExceptions's [AdventOfCode](https://github.com/networkException/AdventOfCode)
+ Daan Breur's [AdventOfCode](https://github.com/daanbreur/AdventofCode)
+ Trojaner's [AdventofCode2020](https://github.com/TrojanerHD/AdventofCode2020)
+ Sammy's [AdventOfCode2020](https://github.com/1Turtle/AdventOfCode2020)
