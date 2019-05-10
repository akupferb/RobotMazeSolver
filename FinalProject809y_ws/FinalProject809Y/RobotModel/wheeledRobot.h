#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H
#include <vector>
#include<iostream>
class WheeledRobot
{
public:
	WheeledRobot();
	int x;
	int y;
	virtual vector<int> Up() override;
	virtual vector<int> Down() override;
	virtual vector<int> Right() override;
	virtual vector<int> Left() override;
	~WheeledRobot();

};

#endif // WHEELEDROBOT_H
