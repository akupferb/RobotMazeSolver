#include "MobileRobot.h"

void MobileRobot::update(s){
	RobotState::RobotState* state = new Robotstate::UpState();
	if (state_stack.empty())
		state->update(state_stack);
	delete state;
}