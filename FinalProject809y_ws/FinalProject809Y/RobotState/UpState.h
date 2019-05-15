#ifndef UPSTATE_H
#define UPSTATE_H
#include "RobotState.h"
#include <string>

class UpState: public RobotState
{
public:
	virtual void update(std::stack<RobotState*>&) override;
	virtual ~UpState(){};
};

#endif // UPSTATE_H