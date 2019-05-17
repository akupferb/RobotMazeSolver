#ifndef RIGHTSTATE_H
#define RIGHTSTATE_H

/**
 * @class RightState
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file RobotState.h
 * @brief This is a derived class from the RobotState class.
 */

#include "RobotState.h"
#include <string>

class RightState: public RobotState
{
public:
	/**
	 * @brief This is a pure virtual method which pushes the current robot state to the stack.
	*/
	virtual void update(std::stack<char>&) override;
	virtual ~RightState(){};
};

#endif // RIGHTSTATE_H 