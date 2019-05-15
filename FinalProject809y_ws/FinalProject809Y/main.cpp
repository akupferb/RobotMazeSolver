#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> newPosition;
vector <vector<int>> pastPositionsT;
int pastPosSizeT = pastPositionsT.size();
vector <vector<int>> pastPositionsW;
int pastPosSizeW = pastPositionsW.size();
vector<int> numericInputs(Maze maze);
void displayPath(vector<vector<int>>, vector<vector<int>>, int, int, vector<int>, vector<int>);

int main()
{
	Maze maze; // Initializes the maze of 'Maze' Class
	int input;
	bool blocked;
	std::vector<int> startT, startW;
	std::vector<int> targetP, targetB;
	std::vector<int> tracked_target;
	std::vector<int> wheeled_target;
	/***************************************************************/
	cout << "Please enter the start position for the tracked robot: ";
	startT = numericInputs(maze);
	maze.changeSpace(startT,'t');
	cout << "Please enter the start position for the wheeled robot: ";
	startW = numericInputs(maze);
	maze.changeSpace(startW,'w');
	cout << "Please enter the coordinates for the plate target: ";
	targetP = numericInputs(maze);
	cout << "Please enter the coordinates for the bottle target: ";
	targetB = numericInputs(maze);
	/*********************************************************************/
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: "; cin >> input;
	}
	if(input == 0) {
		wheeled_target = targetP; tracked_target = targetB;
	} else {
		wheeled_target = targetB; tracked_target = targetP;
	}
	/*********************************************************************/
	WheeledRobot w_robot(startW, wheeled_target);
	MobileRobot *wRobot = &w_robot;
	TrackedRobot t_robot(startT, tracked_target);
	MobileRobot *tRobot = &t_robot;
	/*********************************************************************/
	if(input == 0) {
		targetP = w_robot.getTargetLoc(); targetB = t_robot.getTargetLoc();
		cout << "\ntracked = bottle, wheeled = plate\n" << endl;
	} else {
		targetB = w_robot.getTargetLoc(); targetP = t_robot.getTargetLoc();
		cout << "\ntracked = plate, wheeled = bottle\n" << endl;
	}
	
	/*********************** Main Code Section: **************************/
	while (maze.isGoal(tRobot,t_robot.getTargetLoc())==0) { // This loop will run until the tracked robot reaches its target
		while(1) { 
			// -- Looking Up
			newPosition = t_robot.Up(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				// ------- Update stack with "UP"
				break;
			}
			// -- Looking Right
			newPosition = t_robot.Right(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				// ------- Update stack with "RIGHT"
				break;
			}
			// -- Looking Down
			newPosition = t_robot.Down(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				// ------- Update stack with "DOWN"
				break;
			}
			// -- Looking Left
			newPosition = t_robot.Left(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				// ------- Update stack with "Left"
				break;
			}
			// -- Backtracking
			if (pastPosSizeT==0) {
				cout << "There is no possible path for the Tracked Robot. Program Cancelled! :(\n";
				maze.rewriteX(startW,startT,targetP,targetB); maze.displayMaze(); 
				return 0;
			}
			maze.changeSpace(t_robot.getRobotLoc(),'X');
			for (int i=0; i<pastPosSizeT; ++i) { t_robot.setRobotLoc(pastPositionsT[i]); }
			pastPositionsT.erase(pastPositionsT.end());
			pastPosSizeT = pastPositionsT.size();
			// ------- POP out top of the stack
		}
		maze.changeSpace(t_robot.getRobotLoc(),'-');
		pastPositionsT.push_back(t_robot.getRobotLoc());
		pastPosSizeT = pastPositionsT.size();
		t_robot.setRobotLoc(newPosition);
	}
	cout << "The tracked robot has reached the goal!" << endl;
	
	/**********************************************************************/
	while (maze.isGoal(wRobot,w_robot.getTargetLoc())==0) { // This loop will run until the wheeled robot reaches its target
		while(1) { 
			// -- Looking Up
			newPosition = w_robot.Up(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				// ------- Update stack with "UP"
				break;
			}
			// -- Looking Right
			newPosition = w_robot.Right(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				// ------- Update stack with "RIGHT"
				break;
			}
			// -- Looking Down
			newPosition = w_robot.Down(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				// ------- Update stack with "DOWN"
				break;
			}
			// -- Looking Left
			newPosition = w_robot.Left(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				// ------- Update stack with "Left"
				break;
			}
			// -- Backtracking
			if (pastPosSizeW==0) {
				cout << "There is no possible path for the Wheeled Robot. Program Cancelled! :(";
				maze.rewriteX(startW,startT,targetP,targetB); maze.displayMaze();
				return 0;
			}
			maze.changeSpace(w_robot.getRobotLoc(),'Y');
			for (int i=0; i<pastPosSizeW; ++i) { w_robot.setRobotLoc(pastPositionsW[i]); }
			pastPositionsW.erase(pastPositionsW.end());
			pastPosSizeW = pastPositionsW.size();
			// ------- POP out top of the stack
		}
		maze.changeSpace(w_robot.getRobotLoc(),'|');
		pastPositionsW.push_back(w_robot.getRobotLoc());
		pastPosSizeW = pastPositionsW.size();
		w_robot.setRobotLoc(newPosition);
	}
	cout << "The wheeled robot has reached the goal!" << endl;
	
	/***********************************************************************************/
	
	// Remove WrongTurns from Maze, and display maze and paths taken:
	maze.rewriteX(startW,startT,targetP,targetB);
	maze.displayMaze();
	displayPath(pastPositionsT, pastPositionsW, pastPosSizeT, pastPosSizeW, t_robot.getRobotLoc(), w_robot.getRobotLoc());
	maze.displayMaze();
	return 0;
}

/**********************************************************************************************************************************/

vector<int> numericInputs(Maze maze) {
	int input1, input2;
	cin >> input1 >> input2;
	while(!cin) {
		cin.clear(); // reset failbit
		cin.ignore(1000,'\n'); //skip bad input
		cout << "Invalid Entry, non-numeric input. Please reenter the two inputs: ";
		cin >> input1 >> input2;
	}
	vector<int> inputs;
	inputs = maze.isInputValid(input1, input2);
	cout << "[" << inputs[0] << "," << inputs[1] << "]" << endl;
	return inputs;
}

void displayPath(vector<vector<int>> pastT, vector<vector<int>> pastW, int sizeT, int sizeW, vector<int> finalT, vector<int> finalW) {
	cout << "Symbols:\n' ' = open\n'#' = blocked\n't' = start for tracked robot\n'w' = start for wheeled robot\n";
	cout << "'|' = path for wheeled robot\n'-' = path for tracked robot\n'+' = overlapping paths\n";
	cout << "'b' = bottle target\n'p' = plate target\n";
		 // Loops through all past positions to display direct maze path
	if (sizeT >= sizeW) {
		cout << "\nThe maze paths for the tracked robot and wheeled robots are:\n   t       w   \n";
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
		cout << "\nThe maze paths for the wheeled robot and tracked robots are:\n   w       t   \n";
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