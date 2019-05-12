#ifndef LEFTSTATE_H
#define LEFTSTATE_H
#include "RobotState.h"
class LeftState: RobotState
{
public:
	virtual bool update(std::stack<RobotState*>&) override;
	LeftState();
	~LeftState();

};

#endif // LEFTSTATE_H
