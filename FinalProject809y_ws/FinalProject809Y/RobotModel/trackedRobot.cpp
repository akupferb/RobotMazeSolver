#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

	TrackedRobot::TrackedRobot(int x, int y, Targets t) { // add is valid check
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
	
	vector<int> TrackedRobot::Up(int x,int y){
		x=x-1;
		y=y;
		vector<int> up{x,y};
		return up;
		}
	vector<int> TrackedRobot::Down(int x,int y){
		x=x+1;
		y=y;
		vector<int> down{x,y};
		return down;
		} 
	vector<int>  TrackedRobot::Right(int x,int y){
		x=x;
		y=y+1;
		vector<int> right{x,y};
		return right;
		}
	vector<int>  TrackedRobot::Left(int x,int y){
		x=x;
		y=y-1;
		vector<int> left{x,y};
		return left;
		}
	void TrackedRobot::movedUp(int x, int y, Maze maze){
		maze.changeSpace(x,y,'-');
	}
	void TrackedRobot::movedDown(int x, int y, Maze maze){
		maze.changeSpace(x,y,'-');
	}
	void TrackedRobot::movedRight(int x, int y, Maze maze){
		maze.changeSpace(x,y,'-');
	}
	void TrackedRobot::movedLeft(int x, int y, Maze maze){
		maze.changeSpace(x,y,'-');
	}
