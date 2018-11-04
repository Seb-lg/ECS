cmake_minimum_required(VERSION 3.10)
project(ECS)

set(CMAKE_CXX_STANDARD 14)

include_directories(ecs)

add_executable(ECS
        ecs/Ecs.hpp
        ecs/Entity.cpp
        ecs/Entity.hpp
        main.cpp
        ecs/ListComponent.hpp
        test/ComponentTest.hpp)
