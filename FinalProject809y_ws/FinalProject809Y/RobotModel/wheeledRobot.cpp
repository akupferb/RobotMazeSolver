#include "WheeledRobot.h"
using namespace std;

	vector<int> WheeledRobot::Up(int,int){
		x=x-1;
		y=y;
		vector<int> up{x,y};
		return up;
		}
	vector<int>  WheeledRobot::Down(int,int){
		x=x+1;
		y=y;
		vector<int> down{x,y};
		return down;
		} 
	vector<int>  WheeledRobot::Right(int,int){
		x=x;
		y=y+1;
		vector<int> right{x,y};
		return right;
		}
	vector<int>  WheeledRobot::Left(int,int){
		x=x;
		y=y-1;
		vector<int> left{x,y};
		return left;
		}
	void WheeledRobot::movedup(){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::moveddown(){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::movedright(){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::movedleft(){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}


