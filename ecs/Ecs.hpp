//
// Created by seble on 01/11/2018.
//

#ifndef ECS_ECS_HPP
#define ECS_ECS_HPP

#include <unordered_map>
#include <vector>
#include <iostream>
#include "ListComponent.hpp"

namespace ecs{
    class Ecs {
    public:

        Ecs() {}

        template<typename T>
        void addComponent(ID id, T component){
            _deleteIds[id].emplace_back(hidden::ListComponent<T>::get().addComponent(id, component));
        }

        template <typename T>
        std::vector<T> &getComponentList(){
            return hidden::ListComponent<T>::get().getComponentList();
        }

        void deleteId(ID id) {
            for (auto &deleting : _deleteIds[id])
                deleting();
            _deleteIds[id].clear();
        }

    private:
        std::unordered_map<ID, std::vector<std::function<void()>>>  _deleteIds;

    };
}


#endif //ECS_ECS_HPP
