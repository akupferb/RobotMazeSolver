#ifndef LEFTSTATE_H
#define LEFTSTATE_H
#include "RobotState.h"
#include <string>

class LeftState: public RobotState
{
public:
	virtual void update(std::stack<char>&) override;
	virtual ~LeftState(){};
};

#endif // LEFTSTATE_H 