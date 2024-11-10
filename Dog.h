#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "犬: ワンワン" << std::endl;
    }
};
