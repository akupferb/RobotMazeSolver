#include "WheeledRobot.h"
using namespace std;
WheeledRobot::WheeledRobot()
{
}
	vector<int> WheeledRobot::Up(int,int){
		x=x;
		y=y+1;
		vector<int> up{x,y};
		return up;
		}
	vector<int>  WheeledRobot::Down(int,int){
		x=x;
		y=y-1;
		vector<int> down{x,y};
		return down;
		} 
	vector<int>  WheeledRobot::Right(int,int){
		x=x+1;
		y=y;
		vector<int> right{x,y};
		return right;
		}
	vector<int>  WheeledRobot::Left(int,int){
		x=x-1;
		y=y;
		vector<int> left{x,y};
		return left;
		}

WheeledRobot::~WheeledRobot()
{
}

