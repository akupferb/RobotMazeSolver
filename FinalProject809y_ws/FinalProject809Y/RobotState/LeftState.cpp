#include "LeftState.h"



	RobotState* state = new LeftState();
	void LeftState::update(std::stack<RobotState*>&, std::string action){
		state_stack.push(action);
	}

