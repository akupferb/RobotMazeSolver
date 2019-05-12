#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"

class DownState: RobotState
{
public:
	virtual void update(std::stack<RobotState*>&, std::string) override;
	DownState();
	~DownState();

};

#endif // DOWNSTATE_H
