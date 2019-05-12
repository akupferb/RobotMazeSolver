#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include<stack>

class RobotState
{
public:
	// attributes

	// methods
	virtual bool update(std::stack<RobotState*>&)
	RobotState();
	virtual ~RobotState(){};
};

#endif // ROBOTSTATE_H
