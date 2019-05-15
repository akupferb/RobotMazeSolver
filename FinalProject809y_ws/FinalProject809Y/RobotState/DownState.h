#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"
#include <string>

class DownState: public RobotState
{
public:
	virtual void update(std::stack<RobotState*>&) override;
	virtual ~DownState(){};
};

#endif // DOWNSTATE_H 