#pragma once

#include <list>
#include "subject.h"

class Ball : public Subject
{
public:
    void registerObserver(std::shared_ptr<Observer> o) override;
    void removeObserver(std::shared_ptr<Observer> o) override;
    void notifyObservers() override;
private:
    std::list<std::shared_ptr<Observer>> m_ObserverList;
};
