#include <iostream>
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

    auto list = ecs::Ecs::getComponentMap<test>();


    return 0;
}