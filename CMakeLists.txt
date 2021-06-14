cmake_minimum_required(VERSION 3.16)
project(numberSystemConverter)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(src/mainFolder)
include_directories(src/numberConversion)
include_directories(src/numberCheck)
include_directories(src/include)
include_directories(src/cli)

add_executable(numberSystemConverter
        src/mainFolder/mainfile.cpp
        src/numberCheck/numberCheck.cpp
        src/numberConversion/convertToNewBase.cpp
        src/numberConversion/convertToTen.cpp
        src/numberConversion/convertNumberFunction.cpp
        src/include/includeLibrary.h
        src/cli/terminalSize.cpp
        src/cli/drawCLI.cpp
        )

