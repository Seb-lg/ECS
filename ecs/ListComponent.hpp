//
// Created by seble on 01/11/2018.
//

#ifndef ECS_LISTCOMPONENT_HPP
#define ECS_LISTCOMPONENT_HPP

#include <vector>
#include <functional>
#include "Entity.hpp"

namespace hidden {
    template <typename T>
    class ListComponent {
    public:
        static ListComponent<T> &get() {
            static ListComponent<T> listComponent;

            return listComponent;
        }

        std::function<void()> addComponent(ID id, T component) {
            _ids.emplace_back(id);
            _component.emplace_back(component);
            return ([id, this](){
                int i = 0;
                auto ids = this->_ids.begin();
                for (ids; *ids != id; ids++, i++);

                auto cpnts = this->_component.begin();
                for (cpnts; i != 0; i--, cpnts++);
                _component.erase(cpnts);
            });
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
