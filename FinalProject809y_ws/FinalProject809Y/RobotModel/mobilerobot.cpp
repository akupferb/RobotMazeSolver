
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

std::stack<char> MobileRobot::reverseStack(std::stack<char> state_stack){
	std::stack<char> reversed_stack;
	while (!state_stack.empty()) {
		reversed_stack.push(state_stack.top());
		state_stack.pop();
	}
	return reversed_stack;
}
