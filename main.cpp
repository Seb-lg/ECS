#include <iostream>
#include "ecs/Ecs.hpp"

struct test {
        test() {}
        test(bool dis, std::string str) {
            this->display = dis;
            this->str = str;
        }
        bool display;
        std::string str;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ID id;

    for (int i = 0; i < 150000 ; i++) {
        id = ecs::entity::Entity::getId();
        ecs::Ecs::addComponent<test>(id, i % 2 == 0, "AGA" + std::to_string(i));
    }
    auto list = ecs::Ecs::getComponentMap<test>();

    for (auto o : list) {
        for (auto i : list) {
        	if (i.second.str != std::string("AGA12860"))
        		std::cout << i.second.str << std::endl;
        }
	    std::cout << o.second.str << std::endl;
    }


    return 0;
}