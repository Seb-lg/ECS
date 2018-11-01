//
// Created by seble on 01/11/2018.
//

#ifndef ECS_LISTCOMPONENT_HPP
#define ECS_LISTCOMPONENT_HPP

#include <vector>
#include "Entity.hpp"

namespace hidden {
    template <typename T>
    class ListComponent {
    public:
        static ListComponent<T> &get() {
            static ListComponent<T> listComponent;

            return listComponent;
        }

        void addComponent(ID id, T component) {
            _ids.emplace_back(id);
            _component.emplace_back(component);
        }

        std::vector<T> &getComponentList() {
            return _component;
        }

    private:
        std::vector<ID> _ids;
        std::vector<T>  _component;
    };
}


#endif //ECS_LISTCOMPONENT_HPP
