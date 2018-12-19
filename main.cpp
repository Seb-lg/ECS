#include <iostream>
#include <Time.hpp>
#include "ecs/Ecs.hpp"

struct test {
        test() {
                this->display = false;
        }
        test(bool dis, std::string &str) {
            this->display = dis;
            this->str = str;
        }
        bool display;
        std::string str;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    ID id;

    for (int i = 0; i < 1100; i++) {
    	id = ecs::entity::Entity::getId();
    	ecs::Ecs::addComponent<std::string>(id, "oui");
    	ecs::Ecs::addComponent<int>(id, 5);
    }

    long time = ecs::Time::get(TimeUnit::MilliSeconds);

    for (int i = 0; i < 10000; i++) {
    	auto oui = ecs::Ecs::filter<std::string, int>();

    	if (!oui[0])
    		std::cout << "AH" << std::endl;
    }

    std::cout << ecs::Time::get(TimeUnit::MilliSeconds) - time << std::endl;


    return 0;
}