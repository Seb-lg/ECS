#include <iostream>
#include "ecs/Ecs.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ecs::Ecs oui;
    ID id = ecs::entity::Entity::getId();


    oui.addComponent<int>(id, 9);
    auto non = oui.getComponentList<int>();

    for (auto &o : non) {
        std::cout << o << std::endl;
        o++;
    }

    oui.deleteId(id);

    non = oui.getComponentList<int>();

    for (auto & o : non) {
        std::cout << o << std::endl;
        o++;
    }

    return 0;
}