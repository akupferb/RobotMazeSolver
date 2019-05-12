#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H

#include<vector>
#include "RobotModel/mobilerobot.h"
class TrackedRobot: public MobileRobot {
public:
	TrackedRobot(int, int, Targets);
	virtual std::vector<int> Up(int,int) override;
	virtual std::vector<int> Down(int,int) override;
	virtual std::vector<int> Right(int,int) override;
	virtual std::vector<int> Left(int,int) override;
	virtual void movedup(int,int) override;
	virtual void moveddown(int,int) override;
	virtual void movedright(int,int) override;
	virtual void movedleft(int,int) override;
	virtual std::vector<int> getRobotLoc();
	virtual ~TrackedRobot(){};

};

#endif // TRACKEDROBOT_H
