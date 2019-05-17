/**
 * @class UpState
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file UpState.h
 * @brief This header file defines the UpState class and its associated data members and methods. It is a derived class from RobotState.
 */
#ifndef UPSTATE_H
#define UPSTATE_H
#include "RobotState.h"
#include <string>

class UpState: public RobotState
{
public:
	/**
	 * @brief This function pushes the 'UP' robot state to the top of the stack as a character 'U'
	 * @param state_stack The stack of characters to which the actions are being pushed
	 * @return None
	*/
	virtual void update(std::stack<char>&) override;
};

#endif // UPSTATE_H