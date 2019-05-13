#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

TrackedRobot::TrackedRobot(int x, int y, std::vector<int> goal) {
	while(x == goal[0] && y == goal[1]) {
		std::cout << "Invalid start position. Please enter different coordinates for tracked robot: ";
		std::cin >> x>>y;
	}
	current_position.push_back(x);
	current_position.push_back(y);
}

//void setRobotLoc(std::vector<int> pos) {
//	TrackedRobot::current_position = pos;
//}

std::vector<int> TrackedRobot::getRobotLoc() {
	return current_position;
}

char TrackedRobot::getVisitedMarker() {
	return visited_marker;
}

char TrackedRobot::getWrongTurnMarker() {
	return wrong_turn;
}

std::vector<int> TrackedRobot::getGoal() {
	return goal;
}

std::vector<int> TrackedRobot::Up(int x,int y){
	x=x-1;
	y=y;
	std::vector<int> up{x,y};
	return up;
}

std::vector<int> TrackedRobot::Down(int x,int y){
	x=x+1;
	y=y;
	std::vector<int> down{x,y};
	return down;
} 

std::vector<int>  TrackedRobot::Right(int x,int y){
	x=x;
	y=y+1;
	std::vector<int> right{x,y};
	return right;
}

std::vector<int>  TrackedRobot::Left(int x,int y){
	x=x;
	y=y-1;
	std::vector<int> left{x,y};
	return left;
}

//void TrackedRobot::movedSpace(int x, int y){
//	Maze::maze->changeSpace(x,y,'-');
//}
//void TrackedRobot::movedDown(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'-');
//}
//void TrackedRobot::movedRight(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'-');
//}
//void TrackedRobot::movedLeft(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'-');
//}
