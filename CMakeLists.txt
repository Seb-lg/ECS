cmake_minimum_required(VERSION 3.10)
project(ECS)

set(CMAKE_CXX_STANDARD 17)

include_directories(ecs)

add_executable(ECS
        ecs/DataBank.hpp
        ecs/Ecs.hpp
        ecs/Entity.cpp
        ecs/Entity.hpp
        ecs/ComponentList.hpp
        ecs/Time.cpp
        ecs/Time.hpp
        ecs/TimedEvent.cpp
        ecs/TimedEvent.hpp
        ecs/TimedEventAdmin.cpp
        ecs/TimedEventAdmin.hpp

        Workers/ThreadPool.cpp
        Workers/ThreadPool.hpp
        main.cpp)

find_package (Threads)
target_link_libraries (ECS ${CMAKE_THREAD_LIBS_INIT})
