#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

WheeledRobot::WheeledRobot(std::vector<int> xy, std::vector<int> goal) {
	int x = xy[0]; int y = xy[1];
	current_position = xy;
	int xT = goal[0]; int yT = goal[1];
	while(x == xT && y == yT) {
		std::cout << "Invalid: wheeled robot & target share position. Please enter different coordinates for target: ";
		std::cin >> xT >> yT;
	}
	goal[0]=xT; goal[1]=yT;
	target.setTargetLoc(goal);
}

std::vector<int> WheeledRobot::getTargetLoc() {
	return target.getTargetLoc();
}

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


