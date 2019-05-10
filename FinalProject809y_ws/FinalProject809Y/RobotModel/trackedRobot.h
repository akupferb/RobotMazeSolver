#ifndef __ROBOTMODEL_TRACKEDROBOT_H__
#define __ROBOTMODEL_TRACKEDROBOT_H__


class TrackedRobot : public MobileRobot
{
public:
	TrackedRobot();
	int x;
	int y;
	virtual vector<int> Up() override{
		x=x;
		y=y+1;
		vector<int> up{x,y};
		return up;
		}
	virtual vector<int> Down() override{
		x=x;
		y=y-1;
		vector<int> down{x,y};
		return down;
		}
	virtual vector<int> Right() override{
		x=x+1;
		y=y;
		vector<int> right{x,y};
		return right;
		}
	virtual vector<int> Left() override{
		x=x-1;
		y=y;
		vector<int> left{x,y};
		return left;
		}
	~TrackedRobot();

};


#endif // __ROBOTMODEL_TRACKEDROBOT_H__
