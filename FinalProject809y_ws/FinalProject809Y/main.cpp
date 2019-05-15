#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void connectTarget(MobileRobot*, MobileRobot*, Targets, Targets);
void displayPath(vector<vector<int>>, vector<vector<int>>, int, int, vector<int>, vector<int>);
void findPath(Maze*, MobileRobot*, MobileRobot*, vector<vector<int>> &, int &);

vector <vector<int>> pastPosTracked; int sizeTracked = pastPosTracked.size();
vector <vector<int>> pastPosWheeled; int sizeWheeled = pastPosWheeled.size();

int main()
{
	Maze maze; // Initialize a maze of 'Maze' Class
	Maze* maze_pointer = &maze; // Initialize a pointer to the maze
	TrackedRobot tracked_robot(maze_pointer);
	MobileRobot *tracked_pointer = &tracked_robot;
	WheeledRobot wheeled_robot(maze_pointer);
	MobileRobot *wheeled_pointer = &wheeled_robot;
	cout << "Please enter the coordinates for the plate target: ";
	Targets plate(maze.numericInputs());
	cout << "Please enter the coordinates for the bottle target: ";
	Targets bottle(maze.numericInputs());
	connectTarget(tracked_pointer, wheeled_pointer, plate, bottle);
	
	/*********************** Maze Solver Section: **************************/
	// Solve path for Tracked Robot:
	findPath(maze_pointer, tracked_pointer, wheeled_pointer, pastPosTracked, sizeTracked);
	// Solve path for Wheeled Robot:
	findPath(maze_pointer, wheeled_pointer, tracked_pointer, pastPosWheeled, sizeWheeled);
	
	// Remove WrongTurns from Maze, and display maze and paths taken:
	maze.rewrite(tracked_pointer,wheeled_pointer,plate.getTargetLoc(),bottle.getTargetLoc());
	maze.displayMaze();
	// display indeces of paths taken by both robots:
	displayPath(pastPosTracked, pastPosWheeled, sizeTracked, sizeWheeled, tracked_robot.getRobotLoc(), wheeled_robot.getRobotLoc());
	maze.displayMaze();
	return 0;
}



/***************************************** Methods used within the Main: *********************************************/

void connectTarget(MobileRobot* tRobot, MobileRobot* wRobot, Targets plate, Targets bottle) {
	int input;
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: "; cin >> input;
	}
	if(input == 0) {
		wRobot->setTargetLoc(plate.getTargetLoc()); tRobot->setTargetLoc(bottle.getTargetLoc());
		cout << "\ntracked = bottle, wheeled = plate\n" << endl;
	} else {
		wRobot->setTargetLoc(bottle.getTargetLoc()); tRobot->setTargetLoc(plate.getTargetLoc());
		cout << "\ntracked = plate, wheeled = bottle\n" << endl;
	}
}

void displayPath(vector<vector<int>> pastT, vector<vector<int>> pastW, int sizeT, int sizeW, vector<int> finalT, vector<int> finalW) {
	cout << "Symbols:\n' ' = open\n'#' = blocked\n't' = start for tracked robot\n'w' = start for wheeled robot\n";
	cout << "'|' = path for wheeled robot\n'-' = path for tracked robot\n'+' = overlapping paths\n";
	cout << "'b' = bottle target\n'p' = plate target\n";
		 // Loops through all past positions to display direct maze path
	if (sizeT >= sizeW) {
		cout << "\nThe maze paths for the tracked robot and wheeled robots are:\n   t      w   \n";
		for (int i=0; i<sizeT; ++i) {
			if (i<sizeW)
				cout << "[" << pastT[i][0] << "," << pastT[i][1] << "] [" << pastW[i][0] << "," << pastW[i][1] << "]" << endl;
			else if (i==sizeW)
				cout << "[" << pastT[i][0] << "," << pastT[i][1] << "] [" << finalW[0] << "," << finalW[1] << "]" << endl;
			else 
				cout << "[" << pastT[i][0] << "," << pastT[i][1] << "]" << endl;
		}
		cout << "[" << finalT[0] << "," << finalT[1] << "]\n" << endl;
	}
	if (sizeW > sizeT) {
		cout << "\nThe maze paths for the wheeled robot and tracked robots are:\n   w      t   \n";
		for (int i=0; i<sizeW; ++i) {
			if (i<sizeT)
				cout << "[" << pastW[i][0] << "," << pastW[i][1] << "] [" << pastT[i][0] << "," << pastT[i][1] << "]" << endl;
			else if (i==sizeT)
				cout << "[" << pastW[i][0] << "," << pastW[i][1] << "] [" << finalT[0] << "," << finalT[1] << "]" << endl;
			else {
				cout << "[" << pastW[i][0] << "," << pastW[i][1] << "]" << endl;
			}
		}
		cout << "[" << finalW[0] << "," << finalW[1] << "]\n" << endl;
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
				// ------- Update stack with "UP"
				break;
			}
			// -- Looking Right
			newPosition = robot->Right(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				// ------- Update stack with "RIGHT"
				break;
			}
			// -- Looking Down
			newPosition = robot->Down(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				// ------- Update stack with "DOWN"
				break;
			}
			// -- Looking Left
			newPosition = robot->Left(robot->getRobotLoc()[0],robot->getRobotLoc()[1]);
			blocked = maze->isObstacle(newPosition[0],newPosition[1],robot);
			if (blocked != true) {
				// ------- Update stack with "Left"
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
			// ------- POP out top of the stack
		}
		maze->changeSpace(robot->getRobotLoc(),robot->getVisitedMarker());
		pastPos.push_back(robot->getRobotLoc());
		pastPosSize = pastPos.size();
		robot->setRobotLoc(newPosition);
	}
	cout << "The " << robot->getName() << " Robot has reached the goal!" << endl;
	return;
}