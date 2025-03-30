cmake_minimum_required(VERSION 3.30)
project(natatie_bonus_ssd)

set(CMAKE_CXX_STANDARD 20)

add_executable(natatie_bonus_ssd main.cpp
       Duck.cpp
        Duck.h
        Lane.cpp
        Lane.h
        main.cpp
        OrderedSet.cpp
        OrderedSet.h
        data.txt
        pb_r5.h
        pb_r5.cpp
        pbr5_test.h
        pbr5_test.cpp
)
