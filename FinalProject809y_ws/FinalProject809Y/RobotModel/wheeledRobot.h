#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H
#include <vector>
#include "mobilerobot.h"
class WheeledRobot: public MobileRobot
{
public:
	WheeledRobot();
	virtual std::vector<int> Up(int,int) override;
	virtual std::vector<int> Down(int,int) override;
	virtual std::vector<int> Right(int,int) override;
	virtual std::vector<int> Left(int,int) override;
	virtual void movedup() override;
	virtual void moveddown() override;
	virtual void movedright() override;
	virtual void movedleft() override;
	virtual ~WheeledRobot(){};

};

#endif // WHEELEDROBOT_H
