#ifndef __ROBOTMODEL_MOBILEROBOT_H__
#define __ROBOTMODEL_MOBILEROBOT_H__

class MobileRobot
{
public:
	MobileRobot();
	virtual vector<int> Up()=0;
	virtual vector<int> Down()=0;
	virtual vector<int> Right()=0;
	virtual vector<int> Left()=0;
	virtual ~MobileRobot();

};

#endif // __ROBOTMODEL_MOBILEROBOT_H__
