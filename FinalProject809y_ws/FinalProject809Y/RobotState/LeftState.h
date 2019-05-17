#ifndef LEFTSTATE_H
#define LEFTSTATE_H

/**
 * @class LeftState
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file LeftState.h
 * @brief This is a derived class from the RobotState class.
 */

#include "RobotState.h"
#include <string>

class LeftState: public RobotState
{
public:
	/**
	 * @brief This is a overridden method definition which pushes the current robot state to the stack.
	*/
	virtual void update(std::stack<char>&) override;
	virtual ~LeftState(){};
};

#endif // LEFTSTATE_H 