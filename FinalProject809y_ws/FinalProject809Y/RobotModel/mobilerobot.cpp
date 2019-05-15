
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

void MobileRobot::update(std::string action){
	if (action=="up") {
		RobotState* state = new UpState();
		if (state_stack.empty())
			state->update(state_stack);
		delete state;
	}
	if (action=="right") {
		RobotState* state = new RightState();
		state->update(state_stack);
		delete state;
	}
	if (action=="down") {
		RobotState* state = new DownState();
		state->update(state_stack);
		delete state;
	}
	if(action=="left") {
		RobotState* state = new LeftState();
		state->update(state_stack);
		delete state;
	}
}
