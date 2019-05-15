#include "RightState.h"

void RightState::update(std::stack<RobotState*>& state_stack){
		state_stack.push(this);
}