#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include <iostream>
#include <vector>
#include <string>

TrackedRobot::TrackedRobot(std::vector<int> xy, std::vector<int> goal) {
	current_position = xy;
	while(xy[0] == goal[0] && xy[1] == goal[1]) {
		std::cout << "Invalid: tracked robot & target share position. Please enter different coordinates for target: ";
		std::cin >> goal[0] >> goal[1];
	}
	target.setTargetLoc(goal);
}

std::vector<int> TrackedRobot::getTargetLoc() {
	return target.getTargetLoc();
}

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