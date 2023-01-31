#pragma once

#include "observer.h"

class Dog : public Observer
{
public:
    explicit Dog(const std::string& id) :
        Observer(id)
    {
    }
    void update() override;
};
