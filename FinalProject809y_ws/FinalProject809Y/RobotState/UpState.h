#ifndef UPSTATE_H
#define UPSTATE_H
#include "RobotState.h"
#include <string>
class UpState: public RobotState
{
public:
	UpState():RobotState("Up");
	virtual void update(std::stack<RobotState*>&) override;
	~UpState();

};

#endif // UPSTATE_H