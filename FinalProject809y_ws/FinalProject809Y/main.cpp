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
* @param maze A pointer to the maze
* @param robot A pointer to the tracked robot
* @param robot2 A pointer to the wheeled robot
* @param plate The plate target, passed by reference
* @param bottle The bottle target, passed by reference
* @return None
*/
void connectTarget(Maze*, MobileRobot*, MobileRobot*, Targets &, Targets &);

/**
* @brief This function runs the search algorithm for the robot
* 
* The function utilizes a Depth-First Search algorthim to explore the maze and find the target.
* The order it searches is clockwise, starting from UP. Each potential position is checked using
* Maze class functions, and if the path is open, a move is made. Then, the index of the previous
* position is added to the positions 2D vector and the move state is pushed to the top of the stack.
* If at any point no move can be made, the robot backtracks to its last position and the top of
* the stack is popped out. When the robot finally reaches the goal, a message is displayed. Then, 
* the robot stack is saved to a new empty stack and returned. Finally, the robot stack is swapped
* with an empty stack to prepare it for the next robot run.
* @param maze A pointer to the maze
* @param robot A pointer to the robot currently searching the maze
* @param robot2 A pointer to the other robot
* @param pastPos A 2D vector of past positions passed by reference
* @param pastPosSize The size of the 2D vector passed by reference
* @return Stack of characters for robot states
*/
stack<char> findPath(Maze*, MobileRobot*, MobileRobot*, vector<vector<int>> &, int &);
/**
* @brief This function displays the indices and directions of the paths taken by both robots
* 
* The function displays the order of moves taken by both robots, showing the longer path on the
* left by checking the size variables. It also displays the direction of moves made from the stack.
* It displays the results with related headers.
* @param pastT A 2D vector of past positions of the Tracked Robot
* @param pastW A 2D vector of past positions of the Wheeled Robot
* @param finalT The final position of the Tracked Robot
* @param finalW The final position of the Wheeled Robot
* @param sizeT The size of the past positions vector of the Tracked Robot
* @param sizeW The size of the past positions vector of the Wheeled Robot
* @param stackT The state stack for the Tracked Robot
* @param stackW The state stack for the Wheeled Robot
* @return None
*/
void displayPath(vector<vector<int>>, vector<vector<int>>, int, int, stack<char>, stack<char>);

vector<vector<int>> positionsTracked; ///< Initialize variable to store tracked robot positions
int posSizeTracked = positionsTracked.size(); ///< Initialize variable to store size of tracked robot positions vector
vector<vector<int>> positionsWheeled; ///< Initialize variable to store wheeled robot positions
int posSizeWheeled = positionsWheeled.size(); ///< Initialize variable to store size of wheeled robot positions vector

/**
* @brief This is the main function
* @return 0 Exit status
*/
int main()
{
	Maze maze; // Initialize a maze of 'Maze' Class
	Maze* maze_pointer = &maze; // Initialize a pointer to the maze
	maze.displayMaze();
	TrackedRobot tracked_robot(maze_pointer); // Initialize a robot of 'TrackedRobot' Class
	MobileRobot *tracked_pointer = &tracked_robot; // Initialize a pointer to the tracked robot
	WheeledRobot wheeled_robot(maze_pointer); // Initialize a robot of 'WheeledRobot' Class
	MobileRobot *wheeled_pointer = &wheeled_robot; // Initialize a pointer to the wheeled robot
	cout << "Please enter the coordinates for the plate target: ";
	Targets plate(maze.numericInputs()); // Initialize the plate target of 'Targets' Class
	cout << "Please enter the coordinates for the bottle target: ";
	Targets bottle(maze.numericInputs()); // Initialize the bottle target of 'Targets' Class
	connectTarget(maze_pointer, tracked_pointer, wheeled_pointer, plate, bottle);
	
	/************************ Maze Solver: **************************/
	// Solve path for Tracked Robot:
	stack<char> tracked_stack = findPath(maze_pointer, tracked_pointer, wheeled_pointer, positionsTracked, posSizeTracked);
	// Solve path for Wheeled Robot:
	stack<char> wheeled_stack = findPath(maze_pointer, wheeled_pointer, tracked_pointer, positionsWheeled, posSizeWheeled);
	
	// Display indices of paths taken by both robots:
	displayPath(positionsTracked, positionsWheeled, posSizeTracked, posSizeWheeled, tracked_stack, wheeled_stack);
	// Remove WrongTurns from Maze, and display maze and paths taken:
	maze.rewrite(tracked_pointer,wheeled_pointer,plate.getTargetLoc(),bottle.getTargetLoc());
	maze.displayMaze();
	return 0;
}




/***************************************** Methods used within the Main: *********************************************/

void connectTarget(Maze* maze, MobileRobot* tRobot, MobileRobot* wRobot, Targets &plate, Targets &bottle) {
	int input;
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: "; cin >> input;
	}
	tRobot->setTargetLoc({0,0}); wRobot->setTargetLoc({0,0});
		if(input == 0) {
			vector<int> temp = tRobot->checkTarget(bottle.getTargetLoc());
			bottle.setTargetLoc(tRobot->checkTarget(maze->isInputValid(temp[0],temp[1])));
			temp = wRobot->checkTarget(plate.getTargetLoc());
			plate.setTargetLoc(wRobot->checkTarget(maze->isInputValid(temp[0],temp[1])));
			cout << "\ntracked => bottle, wheeled => plate\n" << endl;
		} else {
			vector<int> temp = tRobot->checkTarget(plate.getTargetLoc());
			plate.setTargetLoc(tRobot->checkTarget(maze->isInputValid(temp[0],temp[1])));
			temp = wRobot->checkTarget(bottle.getTargetLoc());
			bottle.setTargetLoc(wRobot->checkTarget(maze->isInputValid(temp[0],temp[1])));
			cout << "\ntracked => plate, wheeled => bottle\n" << endl;
		}
}

stack<char> findPath(Maze* maze, MobileRobot* robot, MobileRobot* robot2, vector<vector<int>> &pastPos, int &pastPosSize) {
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
				stack<char> blank;
				return blank;
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
	pastPos.push_back(robot->getRobotLoc());
	pastPosSize = pastPos.size();
	stack<char> empty_stack;
	stack<char> robot_stack = robot->reverseStack(robot->state_stack);
	robot->state_stack.swap(empty_stack);
	return robot_stack;
}


void displayPath(vector<vector<int>> pastT, vector<vector<int>> pastW, int sizeT, int sizeW, stack<char> stateT, stack<char> stateW) {
	// Loops through all past positions to display direct maze path
	if (sizeW == 0) {
		cout << "\nThe maze path for the tracked robot is:\n";
		for (int i=1; i<sizeT; ++i) { cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"] "<<stateT.top()<<endl; stateT.pop(); }
	}
	else if (sizeT == 0) {
		cout << "\nThe maze path for the wheeled robot is:\n";
		for (int i=1; i<sizeW; ++i) { cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"] "<<stateW.top()<<endl; stateW.pop(); }
	}
	else if (sizeT >= sizeW) {
		cout << "\nThe maze paths for the tracked and wheeled robots, respectively, are:\n  t          w\n";
		cout<<"["<<pastT[0][0]<<","<<pastT[0][1]<<"]    ["<<pastW[0][0]<<","<<pastW[0][1]<<"] "<<endl;
		for (int i=1; i<sizeT; ++i) {
			if (i<sizeW) {
				cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"] "<<stateT.top()<<"  ["<<pastW[i][0]<<","<<pastW[i][1]<<"] "<<stateW.top()<<endl;
				stateT.pop(); stateW.pop();
			} else {
				cout<<"["<<pastT[i][0]<<","<<pastT[i][1]<<"] "<<stateT.top()<<endl;
				stateT.pop();
			}
		}
	}
	else if (sizeW > sizeT) {
		cout << "\nThe maze paths for the wheeled and tracked robots, respectively, are:\n  w          t\n";
		cout<<"["<<pastW[0][0]<<","<<pastW[0][1]<<"]    ["<<pastT[0][0]<<","<<pastT[0][1]<<"] "<<endl;
		for (int i=1; i<sizeW; ++i) {
			if (i<sizeT) {
				cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"] "<<stateW.top()<<"  ["<<pastT[i][0]<<","<<pastT[i][1]<<"] "<<stateT.top()<<endl;
				stateW.pop(); stateT.pop();
			} else {
				cout<<"["<<pastW[i][0]<<","<<pastW[i][1]<<"] "<<stateW.top()<<endl;
				stateW.pop();
			}
		}
	}
}
