/**
 * @class DownState
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file DownState.h
 * @brief This header file defines the DownState class and its associated data members and methods. It is a derived class from RobotState.
 */
 
#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"
#include <string>

class DownState: public RobotState
{
public:
	/**
	 * @brief This function pushes the 'DOWN' robot state to the top of the stack as a character 'D'
	 * @param The stack of characters to which the actions are being pushed
	 * @return None
	*/
	virtual void update(std::stack<char>&) override;
	virtual ~DownState(){};
};

#endif // DOWNSTATE_H 