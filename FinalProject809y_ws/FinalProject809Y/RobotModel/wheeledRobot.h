#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H

#include <vector>
#include "RobotModel/mobilerobot.h"

class WheeledRobot: public MobileRobot {
public:
	WheeledRobot(int, int, Targets);
	virtual std::vector<int> Up(int,int) override;
	virtual std::vector<int> Down(int,int) override;
	virtual std::vector<int> Right(int,int) override;
	virtual std::vector<int> Left(int,int) override;
	virtual void movedup(int,int) override;
	virtual void moveddown(int,int) override;
	virtual void movedright(int,int) override;
	virtual void movedleft(int,int) override;
	virtual std::vector<int> getRobotLoc();
	virtual ~WheeledRobot(){};

};

#endif // WHEELEDROBOT_H
