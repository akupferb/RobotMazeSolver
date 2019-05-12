#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"
#include <string>
class DownState: public RobotState
{
public:
	DownState():RobotState("Down");
	virtual void update(std::stack<RobotState*>&) override;
	~DownState();

};

#endif // DOWNSTATE_H