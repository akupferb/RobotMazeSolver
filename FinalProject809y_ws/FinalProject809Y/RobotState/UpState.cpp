#include "UpState.h"



RobotState* state = new UpState();
	void UpState::update(std::stack<RobotState*>&, std::string action){
		state_stack.push(action);
	}