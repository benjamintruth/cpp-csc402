cmake_minimum_required(VERSION 3.29)
project(sanning_rien_csc402prog5)

set(CMAKE_CXX_STANDARD 20)

add_executable(sanning_rien_csc402prog5 main.cpp
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        Faculty.cpp
        Faculty.h
        TeachingAsst.cpp
        TeachingAsst.h)
