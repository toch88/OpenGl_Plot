#pragma once
class Listener
{
public:
	virtual void handleEvent() = 0;
	virtual void handleEvent(int ID)=0;
};