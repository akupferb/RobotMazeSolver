#ifndef UPSTATE_H
#define UPSTATE_H
#include "RobotState.h"

class UpState: RobotState
{
public:
	virtual bool update(std::stack<RobotState*>&) override;
	UpState();
	~UpState();

};

#endif // UPSTATE_H
