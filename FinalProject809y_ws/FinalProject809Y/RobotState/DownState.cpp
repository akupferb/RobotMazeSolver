#include "DownState.h"


	RobotState* state = new DownState();
	void DownState::update(std::stack<RobotState*>&, std::string action){
		state_stack.push(action);
	}

