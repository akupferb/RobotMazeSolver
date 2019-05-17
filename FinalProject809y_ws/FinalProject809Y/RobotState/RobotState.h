/**
 * @class RobotState
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file RobotState.h
 * @brief This header file defines the RobotState class and its associated data members and methods. This is an abstract class.
 */
#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include <stack>
#include <string>


class RobotState
{
public:
	/**
	 * @brief This is a pure virtual method definition for updating the stack with the robot state
	*/
	virtual void update(std::stack<char>&){}
	/**
	 * @brief This is a virtual destructor
	*/
	virtual ~RobotState(){};
};


#endif // ROBOTSTATE_H 