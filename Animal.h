#pragma once
#include <iostream>

class Animal {
public:
    
    virtual ~Animal() = default;

    virtual void makeSound() const = 0;
};
