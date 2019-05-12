#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include<stack>

class RobotState
{
public:
	// attributes
	// Defining stack
	std::stack<RobotState*>state_stack;
	// methods
	virtual bool update(std::stack<RobotState*>&)
	RobotState();
	virtual ~RobotState(){};
};

#endif // ROBOTSTATE_H
