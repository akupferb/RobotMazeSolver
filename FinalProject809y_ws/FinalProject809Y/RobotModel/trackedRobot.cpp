#include "TrackedRobot.h"
using namespace std;
TrackedRobot::TrackedRobot()
{
}

virtual vector<int> TrackedRobot::Up() override{
		x=x;
		y=y+1;
		vector<int> up{x,y};
		return up;
		}
	virtual vector<int> TrackedRobot::Down() override{
		x=x;
		y=y-1;
		vector<int> down{x,y};
		return down;
		} 
	virtual vector<int>  TrackedRobot::Right() override{
		x=x+1;
		y=y;
		vector<int> right{x,y};
		return right;
		}
	virtual vector<int>  TrackedRobot::Left() override{
		x=x-1;
		y=y;
		vector<int> left{x,y};
		return left;
		}

TrackedRobot::~TrackedRobot()
{
}

