#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H
#include<vector>
#include "mobilerobot.h"
class TrackedRobot: public MobileRobot
{
public:
	TrackedRobot();
	virtual std::vector<int> Up(int,int) override;
	virtual std::vector<int> Down(int,int) override;
	virtual std::vector<int> Right(int,int) override;
	virtual std::vector<int> Left(int,int) override;
	virtual void movedup() override;
	virtual void moveddown() override;
	virtual void movedright() override;
	virtual void movedleft() override;
	virtual ~TrackedRobot(){};

};

#endif // TRACKEDROBOT_H
