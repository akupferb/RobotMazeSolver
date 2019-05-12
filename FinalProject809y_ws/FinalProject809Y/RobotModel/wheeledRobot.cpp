#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	WheeledRobot::WheeledRobot(int x, int y, Targets t) {
		target = t;
		while(x == target.position[0] && y == target.position[1]) {
			cout << "Invalid start position. Please enter different coordinates: "<< endl;
			cin >> x>>y;
		}
		current_position.push_back(x);
		current_position.push_back(y);
	}

	std::vector<int> TrackedRobot::getRobotLoc() {
		return current_position;
	}

	
	vector<int> WheeledRobot::Up(int x, int y){
		x=x-1;
		y=y;
		vector<int> up{x,y};
		return up;
		}
		
	vector<int>  WheeledRobot::Down(int x, int y){
		x=x+1;
		y=y;
		vector<int> down{x,y};
		return down;
		}
		
	vector<int>  WheeledRobot::Right(int x, int y){
		x=x;
		y=y+1;
		vector<int> right{x,y};
		return right;
		}
		
	vector<int>  WheeledRobot::Left(int x, int y){
		x=x;
		y=y-1;
		vector<int> left{x,y};
		return left;
		}
		
	void WheeledRobot::movedup(int x, int y){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::moveddown(int x, int y){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::movedright(int x, int y){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}
	void WheeledRobot::movedleft(int x, int y){
		if (Maze::maze_arr[x][y]=='-')
			Maze::maze_arr[x][y]=='+';
		else
			Maze::maze_arr[x][y]='|';
	}


