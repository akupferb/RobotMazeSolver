#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotState/RobotState.h"
#include "RobotState/UpState.h"
#include "RobotState/RightState.h"
#include "RobotState/LeftState.h"
#include "RobotState/DownState.h"
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

std::vector<int> TrackedRobot::checkTarget(std::vector<int> goal) {
	
	while(getStart()[0] == goal[0] && getStart()[1] == goal[1]) {
		std::cout << "Invalid: tracked robot & target share position. Please enter different coordinates for target: ";
		std::cin >> goal[0] >> goal[1];
	}
	setTargetLoc(goal);
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

void TrackedRobot::update(std::string action){
	if (action=="up")
	{
		RobotState* state = new UpState();
		state->update(state_stack);
		delete state;
	}
	if (action=="right")
	{
		RobotState* state = new RightState();
		state->update(state_stack);
		delete state;
	}
	if (action=="down")
	{
		RobotState* state = new DownState();
		state->update(state_stack);
		delete state;
	}
	if(action=="left")
	{
		RobotState* state = new LeftState();
		state->update(state_stack);
		delete state;
	}

}