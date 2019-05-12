#ifndef RIGHTSTATE_H
#define RIGHTSTATE_H
#include "RobotState.h"

class RightState: RobotState
{
public:
	virtual bool update(std::stack<RobotState*>&) override;
	RightState();
	~RightState();

};

#endif // RIGHTSTATE_H
