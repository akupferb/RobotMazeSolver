#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <iostream>
#include <vector>
#include <string>

WheeledRobot::WheeledRobot(Maze* maze):MobileRobot() {
	std::cout << "Please enter the start position for the wheeled robot: ";
	start_position = maze->numericInputs();
	current_position = getStart();
	_name = "Wheeled";
	maze->changeSpace(getStart(),'w');
}

std::string WheeledRobot::getName() {
	return _name;
}
std::vector<int> WheeledRobot::getStart() {
	return start_position;
}
std::vector<int> WheeledRobot::getRobotLoc() {
	return current_position;
}
std::vector<int> WheeledRobot::getTargetLoc() {
	return target;
}
char WheeledRobot::getStartMarker() {
	return start_marker;
}
char WheeledRobot::getVisitedMarker() {
	return visited_marker;
}
char WheeledRobot::getWrongTurnMarker() {
	return wrong_turn;
}

std::vector<int> WheeledRobot::Up(int x, int y){
	x=x-1;
	y=y;
	std::vector<int> up{x,y};
	return up;
}

std::vector<int> WheeledRobot::Down(int x, int y){
	x=x+1;
	y=y;
	std::vector<int> down{x,y};
	return down;
}

std::vector<int> WheeledRobot::Right(int x, int y){
	x=x;
	y=y+1;
	std::vector<int> right{x,y};
	return right;
}

std::vector<int> WheeledRobot::Left(int x, int y){
	x=x;
	y=y-1;
	std::vector<int> left{x,y};
	return left;
}
