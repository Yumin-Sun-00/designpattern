#include "ball.h"
#include <algorithm>

void Ball::registerObserver(std::shared_ptr<Observer> o)
{
    //todo: do we need to lock observer?
    if(!o) return;

    const auto identify = [&o](const auto& cit){ return *cit == *o;};
    auto it = std::find_if(m_ObserverList.cbegin(), m_ObserverList.cend(), identify);
    if(it != m_ObserverList.end())
    {
        return;
    }
    else
    {
        m_ObserverList.push_back(o);
    }
}

void Ball::removeObserver(std::shared_ptr<Observer> o)
{
    //todo: do we need to lock observer?
    if(!o) return;

    m_ObserverList.remove_if([&o](const auto& cit){ return *cit == *o;});
}

void Ball::notifyObservers()
{
    for(auto& o : m_ObserverList)
    {
        o->update();
    }
}
