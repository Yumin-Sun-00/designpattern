#pragma once

#include "observer.h"

class Cat : public Observer
{
public:
    explicit Cat(const std::string& id) :
        Observer(id)
    {
    }
    void update() override;

};
