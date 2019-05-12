#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H
#include <vector>
#include<stack>
class MobileRobot
{
public:
	MobileRobot();
	int x;
	int y;
	// Defining stack
	std::stack<RobotState*>state_stack;
	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	virtual void update(std::string);     //  =0 Doubt
	virtual ~MobileRobot(){};
};


#endif // MOBILEROBOT_H
