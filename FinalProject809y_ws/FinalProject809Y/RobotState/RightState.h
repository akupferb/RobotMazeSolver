#ifndef RIGHTSTATE_H
#define RIGHTSTATE_H
#include "RobotState.h"
#include <string>
class RightState: public RobotState
{
public:
	RightState():RobotState("Right"){};
	virtual void update(std::stack<RobotState*>&) override;
	~RightState();

};

#endif // RIGHTSTATE_H