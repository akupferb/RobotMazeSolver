#include "UpState.h"

void UpState::update(std::stack<RobotState*>& state_stack){
	if (state_stack.empty())
		state_stack.push(this);
}
