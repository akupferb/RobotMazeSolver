#include "TrackedRobot.h"
using namespace std;

	vector<int> TrackedRobot::Up(int,int){
		x=x-1;
		y=y;
		vector<int> up{x,y};
		return up;
		}
	vector<int> TrackedRobot::Down(int,int){
		x=x+1;
		y=y;
		vector<int> down{x,y};
		return down;
		} 
	vector<int>  TrackedRobot::Right(int,int){
		x=x;
		y=y+1;
		vector<int> right{x,y};
		return right;
		}
	vector<int>  TrackedRobot::Left(int,int){
		x=x;
		y=y-1;
		vector<int> left{x,y};
		return left;
		}
	void TrackedRobot::movedup(){
		if (Maze::maze_arr[x][y]=='|')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='-';
	}
	void TrackedRobot::moveddown(){
		if (Maze::maze_arr[x][y]=='|')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='-';
	}
	void TrackedRobot::movedright(){
		if (Maze::maze_arr[x][y]=='|')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='-';
	}
	void TrackedRobot::movedleft(){
		if (Maze::maze_arr[x][y]=='|')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='-';
	}
