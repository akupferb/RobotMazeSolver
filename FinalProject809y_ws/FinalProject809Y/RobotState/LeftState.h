/**
 * @class LeftState
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file LeftState.h
 * @brief This header file defines the LeftState class and its associated data members and methods. It is a derived class from RobotState.
 */

#ifndef LEFTSTATE_H
#define LEFTSTATE_H
#include "RobotState.h"
#include <string>

class LeftState: public RobotState
{
public:
	/**
	 * @brief This function pushes the 'LEFT' robot state to the top of the stack as a character 'L'
	 * @param state_stack The stack of characters to which the actions are being pushed
	 * @return None
	*/
	virtual void update(std::stack<char>&) override;
	virtual ~LeftState(){};
};

#endif // LEFTSTATE_H 