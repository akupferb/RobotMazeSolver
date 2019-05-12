#include "RobotModel/MobileRobot.h"
#include "Target/Targets.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void MobileRobot::update(std::string action){
	RobotState::RobotState* state = new Robotstate::UpState();
	if (state_stack.empty())
		state->update(state_stack);
	delete state;
}