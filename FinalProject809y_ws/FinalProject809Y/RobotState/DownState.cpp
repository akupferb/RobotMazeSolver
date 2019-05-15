#include "DownState.h"

void DownState::update(std::stack<RobotState*>& state_stack){
		state_stack.push(this);
} 