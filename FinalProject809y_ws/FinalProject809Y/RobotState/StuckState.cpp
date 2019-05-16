#include "StuckState.h"
#include <stack>
#include <iostream>
void StuckState::update(std::stack<char>& state_stack){
		state_stack.pop();
}

