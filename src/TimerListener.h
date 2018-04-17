#pragma once 
#include "Listener.h"
#include <iostream>
class TimerListener : public Listener
{
  public:
    void handleEvent();
};