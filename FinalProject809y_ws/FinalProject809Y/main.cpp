/**
* @file main.cpp
* @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
* @date 20 May 2019
* @copyright 2019 Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
* @brief This file runs the main code with two robots finding assigned targets in a maze.
*/

#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
* @brief This function links each robot to its assigned target
* 
* The function first checks for a valid input, and then assigns each target position
* to its respective robot using a RobotModel class function that confirms the input.
* It then displays the connectivity in the terminal for the user.
* 
* @param robot A pointer to the tracked robot
* @param robot2 A pointer to the wheeled robot
* @param plate The plate target, passed by reference
* @param bottle The bottle target, passed by reference
* @return None
*/
void connectTarget(MobileRobot*, MobileRobot*, Targets &, Targets &);

/**
* @brief This function runs the search algorithm for the robot
* 
* The function utilizes a Depth-First Search algorthim to explore the maze and find the target.
* The order it searches is clockwise, starting from UP. Each potential position is checked using
* Maze class functions, and if the path is open, a move is made. Then, the index of the previous
* position is added to the pastPos 2D vector and the move state is pushed to the top of the stack.
* If at any point no move can be made, the robot backtracks to its last position and the top of
* the stack is popped out. When the robot finally reaches the goal, a message is displyed.
* @param maze A pointer to the maze
* @param robot A pointer to the robot currently searching the maze
* @param robot2 A pointer to the other robot
* @param pastPos A 2D vector of past positions passed by reference
* @param pastPosSize The size of the 2D vector passed by reference
* @return None
*/
void findPath(Maze*, MobileRobot*, MobileRobot*, vector<vector<int>> &, int &);
/**
* @brief This function displays the indeces of the paths taken by both robots
* 
* The function displays the order of moves taken by both robots, showing the longer path on the
* left by checking the size variables. It then displays the results with related headers.
* @param pastT A 2D vector of past positions of the Tracked Robot
* @param pastW A 2D vector of past positions of the Wheeled Robot
* @param finalT The final position of the Tracked Robot
* @param finalW The final position of the Wheeled Robot
* @param sizeT The size of the past positions vector of the Tracked Robot
* @param sizeW The size of the past positions vector of the Wheeled Robot
* @return None
*/
void displayPath(vector<vector<int>>, vector<vector<int>>, vector<int>, vector<int>, int, int, stack<char>, stack<char>);

vector<vector<int>> pastPosTracked; ///< Initialize variable to store tracked robot positions
int sizeTracked = pastPosTracked.size(); ///< Initialize variable to store size of tracked robot positions vector
vector<vector<int>> pastPosWheeled; ///< Initialize variable to store wheeled robot positions
int sizeWheeled = pastPosWheeled.size(); ///< Initialize variable to store size of wheeled robot positions vector

/**
* @brief This is the main function
* @return 0 Exit status
*/
int main()
{
	Maze maze; // Initialize a maze of 'Maze' Class
	Maze* maze_pointer = &maze; // Initialize a pointer to the maze
	TrackedRobot tracked_robot(maze_pointer); // Initialize a robot of 'TrackedRobot' Class
	MobileRobot *tracked_pointer = &tracked_robot; // Initialize a pointer to the tracked robot
	WheeledRobot wheeled_robot(maze_pointer); // Initialize a robot of 'WheeledRobot' Class
	MobileRobot *wheeled_pointer = &wheeled_robot; // Initialize a pointer to the wheeled robot
	cout << "Please enter the coordinates for the plate target: ";
	Targets plate(maze.numericInputs()); // Initialize the plate target of 'Targets' Class
	cout << "Please enter the coordinates for the bottle target: ";
	Targets bottle(maze.numericInputs()); // Initialize the bottle target of 'Targets' Class
	connectTarget(tracked_pointer, wheeled_pointer, plate, bottle);
	
	/************************ Maze Solver: **************************/
	// Solve path for Tracked Robot:
	findPath(maze_pointer, tracked_pointer, wheeled_pointer, pastPosTracked, sizeTracked);
	// Solve path for Wheeled Robot:
	findPath(maze_pointer, wheeled_pointer, tracked_pointer, pastPosWheeled, sizeWheeled);
	
	// Remove WrongTurns from Maze, and display maze and paths taken:
	maze.rewrite(tracked_pointer,wheeled_pointer,plate.getTargetLoc(),bottle.getTargetLoc());
	maze.displayMaze();
	// display indeces of paths taken by both robots:
	displayPath(pastPosTracked, pastPosWheeled, tracked_robot.getRobotLoc(), wheeled_robot.getRobotLoc(), sizeTracked, sizeWheeled, tracked_robot.state_stack, wheeled_robot.state_stack);
	maze.displayMaze();
	return 0;
}




/***************************************** Methods used within the Main: *********************************************/

void connectTarget(MobileRobot* tRobot, MobileRobot* wRobot, Targets &plate, Targets &bottle) {
	int input;
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: "; cin >> input;
	}
	if(input == 0) {
		bottle.setTargetLoc(tRobot->checkTarget(bottle.getTargetLoc()));
		plate.setTargetLoc(wRobot->checkTarget(plate.getTargetLoc()));
		cout << "\ntracked => bottle, wheeled => plate\n" << endl;
	} else {
		plate.setTargetLoc(tRobot->checkTarget(plate.getTargetLoc()));
		bottle.setTargetLoc(wRobot->checkTarget(bottle.getTargetLoc()));
		cout << "\ntracked => plate, wheeled => bottle\n" << endl;
	}
}

void findPath(Maze* maze, MobileRobot* robot, MobileRobot* robot2, vector<vector<int>> &pastPos, int &pastPosSize) {
	vector<int> newPosition;
	bool blocked;
	while (maze->isGoal(robot,robot->getTargetLoc())==0) { // This loop will run until the tracked robot reaches its target
		while(1) { 
			// -- Looking Up
			newPosition = robot->Up(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				robot->update("up"); // Add 'u' to the stack
				break;
			}
			// -- Looking Right
			newPosition = robot->Right(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				robot->update("right"); // Add 'r' to the stack
				break;
			}
			// -- Looking Down
			newPosition = robot->Down(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				robot->update("down"); // Add 'd' to the stack
				break;
			}
			// -- Looking Left
			newPosition = robot->Left(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				robot->update("left"); // Add 'l' to the stack
				break;
			}
			// -- Backtracking
			if (pastPosSize==0) {
				cout << "There is no possible path for the " << robot->getName() << " Robot! :(\n";
				return;
			}
			maze->changeSpace(robot->getRobotLoc(),robot->getWrongTurnMarker());
			for (int i=0; i<pastPosSize; ++i) { robot->setRobotLoc(pastPos[i]); }
			pastPos.erase(pastPos.end());
			pastPosSize = pastPos.size();
			robot->state_stack.pop(); // pop the top of the stack
		}
		maze->changeSpace(robot->getRobotLoc(),robot->getVisitedMarker());
		pastPos.push_back(robot->getRobotLoc());
		pastPosSize = pastPos.size();
		robot->setRobotLoc(newPosition);
	}
	cout << "The " << robot->getName() << " Robot has reached the goal!" << endl;
	cout << "The stack of the " << robot->getName() << " robot" << endl;
	stack<char> _state_stack = robot->state_stack;
	robot->showStack(_state_stack);
	return;
}

void displayPath(vector<vector<int>> pastT, vector<vector<int>> pastW, vector<int> finalT, vector<int> finalW, int sizeT, int sizeW, stack<char> stateT, stack<char> stateW) {
	cout << "Symbols:\n' ' = open\n'#' = blocked\n't' = start for tracked robot\n'w' = start for wheeled robot\n";
	cout << "'|' = path for wheeled robot\n'-' = path for tracked robot\n'+' = overlapping paths\n";
	cout << "'b' = bottle target\n'p' = plate target\n";
		 // Loops through all past positions to display direct maze path
	if (sizeT >= sizeW) {
		cout << "\nThe maze paths for the tracked robot and wheeled robots are:\n   t      w   \n";
		for (int i=0; i<sizeT; ++i) {
			if (i<sizeW)
				cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"] ["<<pastW[i][0]<<","<<pastW[i][1]<<"]"<<endl;
			else if (i==sizeW)
				cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"] ["<<finalW[0]<<","<<finalW[1]<<"]"<<endl;
			else 
				cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"]"<<endl;
		}
		cout<<"["<<finalT[0]<<","<<finalT[1]<<"]\n"<<endl;
	}
	if (sizeW > sizeT) {
		cout << "\nThe maze paths for the wheeled robot and tracked robots are:\n   w      t   \n";
		for (int i=0; i<sizeW; ++i) {
			if (i<sizeT)
				cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"] ["<<pastT[i][0]<<","<<pastT[i][1]<<"]"<<endl;
			else if (i==sizeT)
				cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"] ["<<finalT[0]<<","<<finalT[1]<<"]"<<endl;
			else {
				cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"]"<<endl;
			}
		}
		cout<<"["<<finalW[0]<<","<<finalW[1]<<"]\n"<<endl;
	}
}