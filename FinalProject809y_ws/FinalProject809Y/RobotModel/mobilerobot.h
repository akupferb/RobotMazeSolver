/**
 * @class MobileRobot
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file MobileRobot.h
 * @brief This header file defines the MobileRobot class and its associated data members and methods. This is an abstract class.
 */
#pragma once
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotState/RobotState.h"
#include <stack>
#include <iostream>
#include <vector>
#include <string>

class MobileRobot {
private:
	std::string _name;
	std::vector<int> target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char start_marker;
	char visited_marker; // | or -
	char wrong_turn; // X or Y
	friend class Maze;
public:
	std::stack<char> state_stack; ///< Stack variable of type character for the list of robot states
	/**
	 * @brief This is a pure virtual method definition for a setter for the target position
	 */
	virtual void setTargetLoc(std::vector<int>) = 0;
	/**
	 * @brief This is a pure virtual method definition for a setter for the robot current position
	 */
	virtual void setRobotLoc(std::vector<int>) = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot name
	 */
	virtual std::string getName() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot start position
	 */
	virtual std::vector<int> getStart() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot current position
	 */
	virtual std::vector<int> getRobotLoc() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot's target position
	 */
	virtual std::vector<int> getTargetLoc() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot start marker
	 */
	virtual char getStartMarker() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot path marker
	 */
	virtual char getVisitedMarker() = 0;
	/**
	 * @brief This is a pure virtual method definition for a getter for the robot backtracking marker
	 */
	virtual char getWrongTurnMarker() = 0;
	/**
	 * @brief This is a pure virtual method definition for checking the validity of the target position
	 */
	virtual std::vector<int> checkTarget(std::vector<int>) = 0;
	/**
	 * @brief This is a pure virtual method definition for obtaining the 'UP' position for the robots
	 */
	virtual std::vector<int> Up(int,int)=0;
	/**
	 * @brief This is a pure virtual method definition for obtaining the 'DOWN' position for the robots
	 */
	virtual std::vector<int> Down(int,int)=0;
	/**
	 * @brief This is a pure virtual method definition for obtaining the 'RIGHT' position for the robots
	 */
	virtual std::vector<int> Right(int,int)=0;
	/**
	 * @brief This is a pure virtual method definition for obtaining the 'LEFT' position for the robots
	 */
	virtual std::vector<int> Left(int,int)=0;
	/**
	 * @brief This is a pure virtual method definition for updating the stack with the robot state
	*/
	virtual void update(std::string) = 0;
	
	/**
	* @brief This function reverses the list of robot states in the stack
	* @param state_stack The stack of robot states
	* @return The reversed stack of robot states
	*/
	std::stack<char> reverseStack(std::stack <char>);
};
