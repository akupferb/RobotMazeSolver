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
	virtual std::vector<int> Up(int,int) override {};
	virtual std::vector<int> Down(int,int) override {};
	virtual std::vector<int> Right(int,int) override {};
	virtual std::vector<int> Left(int,int) override {};
	~WheeledRobot();

};

#endif // WHEELEDROBOT_H
