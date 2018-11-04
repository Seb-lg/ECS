#include <iostream>
#include "ecs/Ecs.hpp"
#include "test/ComponentTest.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ID id = ecs::entity::Entity::getId();


    ecs::Ecs::get().addComponent<int>(id, 9);
    ecs::Ecs::get().addComponent<CpntTest>(id, std::string("JE SUIS UN TEST"), 9);
    //oui.addComponent<std::string>(id, std::string("JE SUIS UN TEST"));

    auto listss = ecs::Ecs::get().getComponentList<int>();

    for (auto o : listss)
    	std::cout << o <<std::endl;

    ecs::Ecs::get().get<int>()[id]++;

    listss = ecs::Ecs::get().getComponentList<int>();

    for (auto o : listss)
    	std::cout << o <<std::endl;

    return 0;
}