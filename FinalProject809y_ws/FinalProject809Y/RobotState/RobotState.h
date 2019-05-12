#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include<stack>
#include <string>

class RobotState
{
public:
	// attributes

	// methods
	virtual void update(std::stack<RobotState*>&,std::string);
	RobotState();
	virtual ~RobotState(){};
};

#endif // ROBOTSTATE_H