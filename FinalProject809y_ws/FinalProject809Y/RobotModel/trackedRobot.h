/**
 * @class TrackedRobot
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @file TrackedRobot.h
 * @brief This header file defines the TrackedRobot class and its associated data members and methods. It is a derived class from MobileRobot.
 */
#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <vector>

class TrackedRobot: public MobileRobot {
private:
	std::string _name;
	std::vector<int> target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char start_marker = 't';
	char visited_marker = '-';
	char wrong_turn = 'X';
public:
	TrackedRobot(); // No args constructor
	/**
	* @brief This is a 1 args constructor
	* 
	* This constructor prompts the user to enter the robot starting position. It then checks that the position
	* is a valid input for the maze, updates the start and current position of the robot, and defines the robot name.
	* @param maze A pointer to the maze
	*/
	TrackedRobot(Maze*);
	
	/**
	* @brief This is an override setter for the robot's target
	* @param pos Position to set for robot's target
	*/
	virtual void setTargetLoc(std::vector<int> pos) override { target = pos; }
	/**
	* @brief This is an override setter for the robot's current position
	* @param pos Position to set for robot
	*/
	virtual void setRobotLoc(std::vector<int> pos) override { current_position = pos; }
	/**
	* @brief This is an override getter for the robot's name
	* @return String of robot name
	*/
	virtual std::string getName() override { return _name; }
	/**
	* @brief This is an override getter for the robot's start position
	* @return Vector of robot start position
	*/
	virtual std::vector<int> getStart() override { return start_position; }
	/**
	* @brief This is an override getter for the robot's current position
	* @return Vector of robot current position
	*/
	virtual std::vector<int> getRobotLoc() override { return current_position; }
	/**
	* @brief This is an override getter for the robot's target
	* @return Vector of robot target position
	*/
	virtual std::vector<int> getTargetLoc() override { return target; }
	/**
	* @brief This is an override getter for the robot's start marker
	* @return Character of robot start marker
	*/
	virtual char getStartMarker() override { return start_marker; }
	/**
	* @brief This is an override getter for the robot's path marker
	* @return Character of robot path marker
	*/
	virtual char getVisitedMarker() override { return visited_marker; }
	/**
	* @brief This is an override getter for the robot's backtracking marker
	* @return Character of robot backtracking marker
	*/
	virtual char getWrongTurnMarker() override { return wrong_turn; }
	
	/**
	* @brief This is an override function that checks that the target does not share its position with the robot start
	* @param goal Vector of the target position
	* @return Vector of the confirmed target position
	*/
	virtual std::vector<int> checkTarget(std::vector<int>);
	/**
	 * @brief This is an override function that obtains the "up" coordinates of the robot
	 * @param x,y The 2D coordinates of current position
	 * @return Vector of new coordinates
	 */
	virtual std::vector<int> Up(int,int);
	/**
	 * @brief This is an override function that obtains the "down" coordinates of the robot
	 * @param x,y The 2D coordinates of current position
	 * @return Vector of new coordinates
	 */
	virtual std::vector<int> Down(int,int);
	/**
	 * @brief This is an override function that obtains the "right" coordinates of the robot
	 * @param x,y The 2D coordinates of current position
	 * @return Vector of new coordinates
	 */
	virtual std::vector<int> Right(int,int);
	/**
	 * @brief This is an override function that obtains the "left" coordinates of the robot
	 * @param x,y The 2D coordinates of current position
	 * @return Vector of new coordinates
	 */
	virtual std::vector<int> Left(int,int);
	/**
	 * @brief This function pushes the current robot state to the top of the stack
	 * @param action A string of the direction of the robot action
	 * @return None
	*/
	virtual void update(std::string);
};

#endif // TRACKEDROBOT_H
