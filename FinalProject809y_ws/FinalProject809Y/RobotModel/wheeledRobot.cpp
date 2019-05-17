/**
 * @class WheeledRobot
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file WheeledRobot.cpp
 * @brief This is a derived class from MobileRobot. This file describes a class for the wheeled robot model and its methods.
 */

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
	maze->changeSpace(getStart(),'w');
}

std::vector<int> WheeledRobot::checkTarget(std::vector<int> goal) {
	
	while(getStart()[0] == goal[0] && getStart()[1] == goal[1]) {
		std::cout << "Invalid: wheeled robot & target share position. Please enter different coordinates for target: ";
		std::cin >> goal[0] >> goal[1];
	}
	setTargetLoc(goal);
	return goal;
}
		/**
	 * @brief This is an overridden method of base class for moving the robot up.
	 * @return Vector of new (x,y) co-ordinates
	 */
std::vector<int> WheeledRobot::Up(int x, int y){
	x=x-1;
	y=y;
	std::vector<int> up{x,y};
	return up;
}
		/**
	 * @brief This is an overridden method of base class for moving the robot down.
	 * @return Vector of new (x,y) co-ordinates
	 */
std::vector<int> WheeledRobot::Down(int x, int y){
	x=x+1;
	y=y;
	std::vector<int> down{x,y};
	return down;
}
		/**
	 * @brief This is an overridden method of base class for moving the robot right.
	 * @return Vector of new (x,y) co-ordinates
	 */
std::vector<int> WheeledRobot::Right(int x, int y){
	x=x;
	y=y+1;
	std::vector<int> right{x,y};
	return right;
}
		/**
	 * @brief This is an overridden method of base class for moving the robot left.
	 * @return Vector of new (x,y) co-ordinates
	 */
std::vector<int> WheeledRobot::Left(int x, int y){
	x=x;
	y=y-1;
	std::vector<int> left{x,y};
	return left;
}

	/**
	 * @brief This is a overridden method implementation which creates a pointer to the robot state for each of the actions.
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