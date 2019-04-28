cmake_minimum_required(VERSION 3.13)
project(Scanner)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scanner
        main.cpp
        Scanner/Scanner.h
        Scanner/Scanner.cpp
        Scanner/estados.h
        Scanner/token.h
        colorTable.h Utils/ErrorReporter.h Utils/ErrorReporter.cpp)