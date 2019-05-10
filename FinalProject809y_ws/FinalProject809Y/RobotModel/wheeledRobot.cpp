#include "WheeledRobot.h"
using namespace std;
WheeledRobot::WheeledRobot()
{
}
	virtual vector<int> WheeledRobot::Up() override{
		x=x;
		y=y+1;
		vector<int> up{x,y};
		return up;
		}
	virtual vector<int>  WheeledRobot::Down() override{
		x=x;
		y=y-1;
		vector<int> down{x,y};
		return down;
		} 
	virtual vector<int>  WheeledRobot::Right() override{
		x=x+1;
		y=y;
		vector<int> right{x,y};
		return right;
		}
	virtual vector<int>  WheeledRobot::Left() override{
		x=x-1;
		y=y;
		vector<int> left{x,y};
		return left;
		}

WheeledRobot::~WheeledRobot()
{
}

