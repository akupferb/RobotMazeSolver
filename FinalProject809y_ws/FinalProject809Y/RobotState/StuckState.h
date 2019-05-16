#ifndef STUCKSTATE_H
#define STUCKSTATE_H
#include <stack>
#include <iostream>
#include "RobotState.h"
class StuckState: public RobotState
{
public:
	virtual void update(std::stack<char>&) override;
	virtual ~StuckState(){};
};

#endif // STUCKSTATE_H
