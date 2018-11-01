cmake_minimum_required(VERSION 3.12)
project(ECS)

set(CMAKE_CXX_STANDARD 14)

include_directories(ecs)

add_executable(ECS
        ecs/Ecs.cpp
        ecs/Ecs.hpp
        ecs/Entity.cpp
        ecs/Entity.hpp
        main.cpp ecs/ListComponent.cpp ecs/ListComponent.hpp)
