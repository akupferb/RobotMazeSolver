#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H
#include <vector>
class MobileRobot
{
public:
	MobileRobot();
	int x;
	int y;
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	virtual ~MobileRobot(){};

};


#endif // MOBILEROBOT_H
