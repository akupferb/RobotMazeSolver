#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H
#include <vector>
class MobileRobot
{
public:
	MobileRobot();
	int x;
	int y;
	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	virtual void update();
	virtual ~MobileRobot(){};

};


#endif // MOBILEROBOT_H
