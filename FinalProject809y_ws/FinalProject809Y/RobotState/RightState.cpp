/**
 * @class RightState
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file LeftState.h
 * @brief This is a derived class from the RobotState class.
 */


#include "RightState.h"
	/**
	 * @brief This is a overridden method implementation which pushes the 'Right' state to the stack as char 'R'
	*/
void RightState::update(std::stack<char>& state_stack){
		state_stack.push('R');
} 