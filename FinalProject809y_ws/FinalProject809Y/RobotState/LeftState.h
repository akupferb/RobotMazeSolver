#ifndef LEFTSTATE_H
#define LEFTSTATE_H
#include "RobotState.h"
#include <string>
class LeftState: public RobotState
{
public:
	LeftState():RobotState("Left");
	virtual void update(std::stack<RobotState*>&) override;
	~LeftState();

};

#endif // LEFTSTATE_H