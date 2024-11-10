#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "猫: ニャーニャー" << std::endl;
    }
};
