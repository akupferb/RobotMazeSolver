#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H
#include <vector>
#include "mobilerobot.h"
class WheeledRobot: MobileRobot
{
public:
	WheeledRobot();
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
	virtual ~WheeledRobot(){};

};

#endif // WHEELEDROBOT_H
