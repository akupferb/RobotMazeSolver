#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

WheeledRobot::WheeledRobot(int x, int y, std::vector<int> goal) {
	while(x == goal[0] && y == goal[1]) {
		std::cout << "Invalid start position. Please enter different coordinates for wheeled robot: ";
		std::cin >> x>>y;
	}
	current_position.push_back(x);
	current_position.push_back(y);
}

//void setRobotLoc(std::vector<int> pos) {
//	WheeledRobot::current_position = pos;
//}

std::vector<int> WheeledRobot::getRobotLoc() {
	return current_position;
}

char WheeledRobot::getVisitedMarker() {
	return visited_marker;
}

char WheeledRobot::getWrongTurnMarker() {
	return wrong_turn;
}

std::vector<int> WheeledRobot::getGoal() {
	return goal;
}

std::vector<int> WheeledRobot::Up(int x, int y){
	x=x-1;
	y=y;
	std::vector<int> up{x,y};
	return up;
}

std::vector<int>  WheeledRobot::Down(int x, int y){
	x=x+1;
	y=y;
	std::vector<int> down{x,y};
	return down;
}

std::vector<int>  WheeledRobot::Right(int x, int y){
	x=x;
	y=y+1;
	std::vector<int> right{x,y};
	return right;
}

std::vector<int>  WheeledRobot::Left(int x, int y){
	x=x;
	y=y-1;
	std::vector<int> left{x,y};
	return left;
}

//void WheeledRobot::movedSpace(int x, int y){
//	Maze::maze->changeSpace(x,y,'|');
//}
//void WheeledRobot::movedDown(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'|');
//}
//void WheeledRobot::movedRight(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'|');
//}
//void WheeledRobot::movedLeft(int x, int y, Maze* maze){
//	maze.changeSpace(x,y,'|');
//}


