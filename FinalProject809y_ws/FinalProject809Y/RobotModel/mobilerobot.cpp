/**
 * @class MobileRobot
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file MobileRobot.cpp
 * @brief This file describes Mobile Robot class which defines the robot model and its methods. This is a base class.
 */


#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotState/UpState.h"
#include "RobotState/DownState.h"
#include "RobotState/LeftState.h"
#include "RobotState/RightState.h"
#include "RobotState/RobotState.h"
#include "RobotModel/MobileRobot.h"
#include <vector>
#include <iostream>
#include <string>
	/**
	 * @brief This is a overridden method implementation which displays the robot states from the stack.
	*/
void MobileRobot::showStack(std::stack <char> state_stack){
	while (!state_stack.empty()) {
		std::cout << state_stack.top() << "\t";
		state_stack.pop();
	}
	std::cout << std::endl;
}
