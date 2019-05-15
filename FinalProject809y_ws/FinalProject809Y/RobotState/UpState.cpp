#include "UpState.h"

void UpState::update(std::stack<RobotState*>& state_stack){
		state_stack.push(this);
}
