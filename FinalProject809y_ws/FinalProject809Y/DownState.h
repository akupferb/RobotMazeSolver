#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"

class DownState: RobotState
{
public:
	virtual bool update(std::stack<RobotState*>&) override;
	DownState();
	~DownState();

};

#endif // DOWNSTATE_H
