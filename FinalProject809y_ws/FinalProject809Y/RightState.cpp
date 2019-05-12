#include "RightState.h"



	RobotState* state = new RightState();
	void RightState::update(std::stack<RobotState*>&, std::string action){
		state_stack.push(action);
	}
