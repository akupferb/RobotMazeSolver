#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H
#include <stack>
#include <string>

/**
 * @class RobotState
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file RobotState.h
 * @brief This class describes the robot state using stacks. This is a base class.
 */


class RobotState
{
public:
	// attributes
	/**
	 * @brief Attribute of type string for storing robot state.
	 */
	std::string state_;
	/**
	 * @brief Constructor for initializing robot state attribute.
	*/
	RobotState(std::string state="RobotState"):state_{state}{}
	// methods
	/**
	 * @brief This is a pure virtual method which pushes or pops the current robot state from the stack.
	*/
	virtual void update(std::stack<char>&){}
	virtual ~RobotState(){};
};


#endif // ROBOTSTATE_H 