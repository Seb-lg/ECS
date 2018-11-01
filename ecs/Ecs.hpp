//
// Created by seble on 01/11/2018.
//

#ifndef ECS_ECS_HPP
#define ECS_ECS_HPP

#include <unordered_map>
#include <vector>
#include <iostream>
#include "Entity.hpp"
#include "ListComponent.hpp"

namespace ecs{
    class Ecs {
    public:

        Ecs() {}

        template<typename T>
        void addComponent(ID id, T component){
            hidden::ListComponent<T>::get().addComponent(id, component);
        }

        template <typename T>
        std::vector<T> &getComponentList(){
            return hidden::ListComponent<T>::get().getComponentList();
        }

    };
}


#endif //ECS_ECS_HPP
