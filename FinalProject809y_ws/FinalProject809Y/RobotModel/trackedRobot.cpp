#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include <iostream>
#include <vector>
#include <string>

TrackedRobot::TrackedRobot(Maze* maze) {
	std::cout << "Please enter the start position for the tracked robot: ";
	start_position = maze->numericInputs();
	current_position = getStart();
	_name = "Tracked";
	maze->changeSpace(getStart(),'t');
}

std::string TrackedRobot::getName() {
	return _name;
}
std::vector<int> TrackedRobot::getStart() {
	return start_position;
}
std::vector<int> TrackedRobot::getRobotLoc() {
	return current_position;
}
std::vector<int> TrackedRobot::getTargetLoc() {
	return target;
}
char TrackedRobot::getStartMarker() {
	return start_marker;
}
char TrackedRobot::getVisitedMarker() {
	return visited_marker;
}
char TrackedRobot::getWrongTurnMarker() {
	return wrong_turn;
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

std::vector<int> TrackedRobot::Right(int x,int y){
	x=x;
	y=y+1;
	std::vector<int> right{x,y};
	return right;
}

std::vector<int> TrackedRobot::Left(int x,int y){
	x=x;
	y=y-1;
	std::vector<int> left{x,y};
	return left;
}
