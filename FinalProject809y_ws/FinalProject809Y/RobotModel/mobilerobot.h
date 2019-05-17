/**
 * @class MobileRobot
 * @author Jagadesh Nischal, Raja Iskala, Bharat Mathur, Ari Kupferberg,Brenda Scheufele
 * @date 12/05/2019
 * @file MobileRobot.h
 * @brief This file describes Mobile Robot class which defines the robot model and its methods. This is an abstract class.
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
	std::stack<char> state_stack;
	// Setters & Getters
	virtual void setTargetLoc(std::vector<int>) = 0;
	virtual void setRobotLoc(std::vector<int>) = 0;
	virtual std::string getName() = 0;
	virtual std::vector<int> getStart() = 0;
	virtual std::vector<int> getRobotLoc() = 0;
	virtual std::vector<int> getTargetLoc() = 0;
	virtual char getStartMarker() = 0;
	virtual char getVisitedMarker() = 0;
	virtual char getWrongTurnMarker() = 0;
//	// Methods
	virtual std::vector<int> checkTarget(std::vector<int>) = 0;
		/**
	 * @brief This is a pure virtual method which define the action 'UP' of the robots.
	 * @params Current position of the robot as x and y.
	 * @return vector consisting of the new co-ordinates for the robot to move
	 */
	virtual std::vector<int> Up(int,int)=0;
		/**
	 * @brief This is a pure virtual method which define the action 'DOWN' of the robots.
	 * @params Current position of the robot as x and y.
	 * @return vector consisting of the new co-ordinates for the robot to move
	 */
	virtual std::vector<int> Down(int,int)=0;
		/**
	 * @brief This is a pure virtual method which define the action 'RIGHT' of the robots.
	 * @params Current position of the robot as x and y.
	 * @return vector consisting of the new co-ordinates for the robot to move
	 */
	virtual std::vector<int> Right(int,int)=0;
		/**
	 * @brief This is a pure virtual method which define the action 'LEFT' of the robots.
	 * @params Current position of the robot as x and y.
	 * @return vector consisting of the new co-ordinates for the robot to move
	 */
	virtual std::vector<int> Left(int,int)=0;
		/**
	 * @brief This is a virtual method definition which pushes the current robot state to the stack.
	*/
	virtual void update(std::string) = 0;
		/**
	 * @brief This is a virtual method definition which displays the robot states from the stack.
	*/
	void showStack(std::stack <char>);
		/**
	 * @brief This is a destructor for the Mobile Robot class.
	 */
	virtual ~MobileRobot(){};
};
