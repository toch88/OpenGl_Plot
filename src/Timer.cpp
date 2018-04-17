
#include "Timer.h"

Timer::Timer()
{
    this->_creationTime = glfwGetTime() * 1000;
}

void Timer::_timerLoop()
{
    this->_currentTick = glfwGetTime() * 1000;

    while (this->isRunning)
    {
        this->loops = 0;
        while (glfwGetTime() * 1000 > this->_currentTick && this->loops < this->MAX_FRAMESKIP)
        {
            //this->_onUpdate->dispatchEvent();
            this->_currentTick += this->SKIP_TICKS;
            this->loops++;
        }
        //this->_onRender->dispatchEvent();
    }
}

void Timer::start()
{
    this->isRunning = true;
}
