#include "EventDispatcher.h"

void EventDispatcher::addListener(Listener* listener)
{
    this->_listeners.push_back(listener);
}

void EventDispatcher::removeListener(std::shared_ptr<Listener> listener)
{
    // this->_listeners.erase(
    //     std::remove(
    //         this->_listeners.begin(),
    //         this->_listeners.end(),
    //         listener),
    //     this->_listeners.end());
}

void EventDispatcher::dispatchEvent()
{
    for (Listener* listener : this->_listeners)
    {
        listener->handleEvent();
    }
}