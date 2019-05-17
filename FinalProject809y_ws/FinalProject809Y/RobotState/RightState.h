/**
 * @class RightState
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file RightState.h
 * @brief This header file defines the RightState class and its associated data members and methods. It is a derived class from RobotState.
 */
#ifndef RIGHTSTATE_H
#define RIGHTSTATE_H
#include "RobotState.h"
#include <string>

class RightState: public RobotState
{
public:
	/**
	 * @brief This function pushes the 'RIGHT' robot state to the top of the stack as a character 'R'
	 * @param state_stack The stack of characters to which the actions are being pushed
	 * @return None
	*/
	virtual void update(std::stack<char>&) override;
};

#endif // RIGHTSTATE_H 