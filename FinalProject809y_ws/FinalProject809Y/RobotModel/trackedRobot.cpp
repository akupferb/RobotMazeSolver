#include "TrackedRobot.h"
using namespace std;
TrackedRobot::TrackedRobot()
{
}

	vector<int> TrackedRobot::Up(int,int){
		x=x;
		y=y+1;
		vector<int> up{x,y};
		return up;
		}
	vector<int> TrackedRobot::Down(int,int){
		x=x;
		y=y-1;
		vector<int> down{x,y};
		return down;
		} 
	vector<int>  TrackedRobot::Right(int,int){
		x=x+1;
		y=y;
		vector<int> right{x,y};
		return right;
		}
	vector<int>  TrackedRobot::Left(int,int){
		x=x-1;
		y=y;
		vector<int> left{x,y};
		return left;
		}

TrackedRobot::~TrackedRobot()
{
}

