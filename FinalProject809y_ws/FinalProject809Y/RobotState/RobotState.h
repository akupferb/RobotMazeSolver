#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include <stack>
#include <string>


class RobotState
{
public:
	// attributes
	std::string state_;
	RobotState(std::string state="RobotState"):state_{state}{}
	// methods
	virtual void update(std::stack<RobotState*>&){}
	virtual ~RobotState(){};
};


#endif // ROBOTSTATE_H 