
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotState/UpState.h"
#include "RobotState/DownState.h"
#include "RobotState/LeftState.h"
#include "RobotState/RightState.h"
#include "RobotState/RobotState.h"
#include "RobotState/StuckState.h"
#include "RobotModel/MobileRobot.h"
#include <vector>
#include <iostream>
#include <string>

void MobileRobot::showStack(std::stack <char> state_stack){
	while (!state_stack.empty()) {
		std::cout << state_stack.top() << std::endl;
		state_stack.pop();
	}
	std::cout << std::endl;
}
