#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H
#include<vector>
#include<iostream>
class TrackedRobot
{
public:
	TrackedRobot();
	virtual vector<int> Up(int x, int y) override;
	virtual vector<int> Down(int x, int y) override;
	virtual vector<int> Right(int x, int y) override;
	virtual vector<int> Left(int x, int y) override;
	~TrackedRobot();

};

#endif // TRACKEDROBOT_H
