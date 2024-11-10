#pragma once
#include "Animal.h"

class Cow : public Animal {
public:
    void makeSound() const override {
        std::cout << "牛: モーモー" << std::endl;
    }
};
