#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "EventDispatcher.h"
#include <future>
#include <iostream>



class Timer
{
private:
  double _currentTick;
  double _creationTime;
  bool isRunning = false;
  const int TICKS_PER_SECOND = 25;
  const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
  const int MAX_FRAMESKIP = 5;
  unsigned int loops;
  float interpolation;

public:
  Timer();
  void start();
  void stop();
  void _timerLoop();  
  std::shared_ptr<EventDispatcher> _onUpdate;  
  std::shared_ptr<EventDispatcher> _onRender;
};