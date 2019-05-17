#ifndef RIGHTSTATE_H
#define RIGHTSTATE_H
#include "RobotState.h"
#include <string>

class RightState: public RobotState
{
public:
	virtual void update(std::stack<char>&) override;
	virtual ~RightState(){};
};

#endif // RIGHTSTATE_H 