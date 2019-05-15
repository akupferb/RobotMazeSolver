#include "LeftState.h"

void LeftState::update(std::stack<RobotState*>& state_stack){
		state_stack.push(this);
} 