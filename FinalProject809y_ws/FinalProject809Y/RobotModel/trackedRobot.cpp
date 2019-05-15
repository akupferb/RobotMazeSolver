#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

TrackedRobot::TrackedRobot(std::vector<int> xy, std::vector<int> goal) {
	int x = xy[0]; int y = xy[1];
	current_position = xy;
	int xT = goal[0]; int yT = goal[1];
	while(x == xT && y == yT) {
		std::cout << "Invalid: tracked robot & target share position. Please enter different coordinates for target: ";
		std::cin >> xT >> yT;
	}
	goal[0]=xT; goal[1]=yT;
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