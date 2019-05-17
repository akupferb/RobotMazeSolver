#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/WheeledRobot.h"
#include "RobotState/RobotState.h"
#include "RobotState/UpState.h"
#include "RobotState/RightState.h"
#include "RobotState/LeftState.h"
#include "RobotState/DownState.h"
#include <iostream>
#include <vector>
#include <string>

WheeledRobot::WheeledRobot(Maze* maze) {
	std::cout << "Please enter the start position for the wheeled robot: ";
	start_position = maze->numericInputs();
	current_position = getStart();
	_name = "Wheeled";
}

std::vector<int> WheeledRobot::checkTarget(std::vector<int> goal) {
	
	while(getStart()[0] == goal[0] && getStart()[1] == goal[1]) {
		std::cout << "Invalid: wheeled robot & target share position. Please enter different coordinates for target: ";
		std::cin >> goal[0] >> goal[1];
	}
	setTargetLoc(goal);
	return goal;
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

/**
 * For the chosen of the four actions, the function creates a pointer to the respective robot state 
 * and then updates the robot stack with that state. Then the pointer is deleted to free up the space.
*/
void WheeledRobot::update(std::string action){
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