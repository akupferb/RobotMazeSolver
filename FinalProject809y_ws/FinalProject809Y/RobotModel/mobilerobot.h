#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H
#include<vector>
#include<iostream>
class MobileRobot
{
public:
	MobileRobot();
	virtual vector<int> Up()=0;
	virtual vector<int> Down()=0;
	virtual vector<int> Right()=0;
	virtual vector<int> Left()=0;
	~MobileRobot();

};

#endif // MOBILEROBOT_H
