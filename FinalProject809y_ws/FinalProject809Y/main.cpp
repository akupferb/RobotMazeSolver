#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
// Symbols:
// ' ' = open
// '#' = blocked
// 't' = start for tracked robot
// 'w' = start for wheeled robot
// 'b' = goal for tracked robot
// 'p' = goal for wheeled robot
// '|' = path for wheeled robot
// '-' = path for tracked robot
// '+' = overlapping paths

//void solveMaze(Maze &, MobileRobot*, MobileRobot*, TrackedRobot, WheeledRobot, vector<int>, vector<int>, vector<int>, vector<int>, vector<int>, vector<int>);
vector <vector<int>> pastPositionsT;
int pastPosSizeT = pastPositionsT.size();
vector <vector<int>> pastPositionsW;
int pastPosSizeW = pastPositionsW.size();
//bool movedPosition;
vector<int> newPosition;

int main()
{
	Maze maze;
	bool blocked;
	std::vector<int> startT, startW;
	std::vector<int> targetP, targetB;
	int input, input_x, input_y;
	std::vector<int> tracked_target;
	std::vector<int> wheeled_target;
	/***************************************************************/
	cout << "Please enter the start position for the wheeled robot: ";
	cin >> input_x >> input_y;
	startW = maze.isInputValid(input_x, input_y);
	maze.changeSpace(startW,'w');
	cout << "Please enter the start position for the tracked robot: ";
	cin >> input_x >> input_y;
	startT = maze.isInputValid(input_x, input_y);
	maze.changeSpace(startT,'t');
	cout << "Please enter the coordinates for the plate target: ";
	cin >> input_x >> input_y;
	targetP = maze.isInputValid(input_x, input_y);
	cout << "Please enter the coordinates for the bottle target: ";
	cin >> input_x >> input_y;
	targetB = maze.isInputValid(input_x, input_y);
	/*********************************************************************/
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: ";
		cin >> input;
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
		cout << "\nwheeled = plate, tracked = bottle\n" << endl;
	} else {
		targetB = w_robot.getTargetLoc(); targetP = t_robot.getTargetLoc();
		cout << "\nwheeled = bottle, tracked = plate\n" << endl;
	}
	/*********************************************************************/
	
//	maze.displayMaze();
	
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
			maze.changeSpace(t_robot.getRobotLoc(),'X');
			for (int i=0; i<pastPosSizeT; ++i) { t_robot.setRobotLoc(pastPositionsT[i]); }
			pastPositionsT.erase(pastPositionsT.end());
			pastPosSizeT = pastPositionsT.size();
			// ------- POP out top of the stack
			//	maze.displayMaze();
		}
		maze.changeSpace(t_robot.getRobotLoc(),'-');
		pastPositionsT.push_back(t_robot.getRobotLoc());
		pastPosSizeT = pastPositionsT.size();
		t_robot.setRobotLoc(newPosition);
	}
	
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
			maze.changeSpace(w_robot.getRobotLoc(),'Y');
			for (int i=0; i<pastPosSizeW; ++i) { w_robot.setRobotLoc(pastPositionsW[i]); }
			pastPositionsW.erase(pastPositionsW.end());
			pastPosSizeW = pastPositionsW.size();
			// ------- POP out top of the stack
			//	maze.displayMaze();
		}
		maze.changeSpace(w_robot.getRobotLoc(),'|');
		pastPositionsW.push_back(w_robot.getRobotLoc());
		pastPosSizeW = pastPositionsW.size();
		w_robot.setRobotLoc(newPosition);
	}
//	solveMaze(maze, tRobot, wRobot, t_robot, w_robot, tracked_target, wheeled_target, startT, startW, targetP, targetB);
	/***********************************************************************************/
	
	// Remove WrongTurns from Maze
	maze.rewriteX(startW,startT,targetP,targetB);
	maze.displayMaze();
	return 0;
}

/***********************************************************/
//void solveMaze(Maze &maze, MobileRobot* tRobot, MobileRobot* wRobot, TrackedRobot t_robot, WheeledRobot w_robot, vector<int> tracked_target, vector<int> wheeled_target,
