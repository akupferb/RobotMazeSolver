#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H
#include<vector>
#include "mobilerobot.h"
class TrackedRobot: MobileRobot
{
public:
	TrackedRobot();
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
	virtual ~TrackedRobot(){};

};

#endif // TRACKEDROBOT_H
