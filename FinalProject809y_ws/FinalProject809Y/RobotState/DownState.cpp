#include "DownState.h"

void DownState::update(std::stack<RobotState*>& state_stack){
	if (!state_stack.empty())
		state_stack.push(this);
}