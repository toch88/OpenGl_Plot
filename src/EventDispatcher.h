#pragma once
#include "Listener.h"
#include <vector>
#include <memory>
class EventDispatcher
{
public:
  void addListener(Listener* listener);
  void removeListener(std::shared_ptr<Listener> listener);
  void dispatchEvent();

protected:
  std::vector<Listener*> _listeners;
};