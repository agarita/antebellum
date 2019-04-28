cmake_minimum_required(VERSION 3.13)
project(Scanner)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scanner
        main.cpp
        scanner.h
        scanner.cpp
        estados.h
        token.h
        prettyPrinting.h prettyPrinting.cpp)