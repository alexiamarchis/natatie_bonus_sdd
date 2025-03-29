cmake_minimum_required(VERSION 3.30)
project(natatie_bonus_sdd)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(natatie_bonus_sdd
    Duck.cpp
    Duck.h
    Lane.cpp
    Lane.h
    main.cpp
    OrderedSet.cpp
    OrderedSet.h
        task_2.h
        task_2.cpp)
