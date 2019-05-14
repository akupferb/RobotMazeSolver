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

void solveMaze(Maze &, MobileRobot*, MobileRobot*, TrackedRobot, WheeledRobot, vector<int>, vector<int>, vector<int>, vector<int>, vector<int>, vector<int>);
vector <vector<int>> pastPositionsT;
int pastPosSizeT = pastPositionsT.size();
vector <vector<int>> pastPositionsW;
int pastPosSizeW = pastPositionsW.size();
bool movedPosition;
vector<int> newPosition;

int main()
{
//	std::string filename = "../maze.txt";
	Maze maze;
	std::vector<int> startT, startW;
	std::vector<int> targetP, targetB;
	int input, input_x, input_y;
	std::vector<int> targets_input;
	std::vector<int> tracked_target;
	std::vector<int> wheeled_target;
	std::vector<Targets> plate_bottle;
	/***************************************************************/
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: ";
		cin >> input;
	}
	targets_input.push_back(input);
	if(input == 1)
		targets_input.push_back(0);
	else
		targets_input.push_back(1);
	/*********************************************************************/
	cout << "Please enter the coordinates for the plate target: ";
	cin >> input_x >> input_y;
	targetP = maze.isInputValid(input_x, input_y);
	maze.changeSpace(targetP,'p');
	Targets plate(targetP);
	/*********************************************************************/
	cout << "Please enter the coordinates for the bottle target: ";
	cin >> input_x >> input_y;
	targetB = maze.isInputValid(input_x, input_y);
	maze.changeSpace(targetB,'b');
	Targets bottle(targetB);
	/*********************************************************************/
	if(targets_input[0] == 0) {
		plate_bottle.push_back(plate); plate_bottle.push_back(bottle);
		wheeled_target = targetP; tracked_target = targetB;
	} else {
		plate_bottle.push_back(bottle); plate_bottle.push_back(plate);
		wheeled_target = targetB; tracked_target = targetP;
	}
	/*********************************************************************/
	cout << "Please enter the start position for the wheeled robot: ";
	cin >> input_x >> input_y;
	startW = maze.isInputValid(input_x, input_y);
	WheeledRobot w_robot(startW, plate_bottle[0].get());
	maze.changeSpace(w_robot.getRobotLoc(),'w');
	/*********************************************************************/
	cout << "Please enter the start position for the tracked robot: ";
	cin >> input_x >> input_y;
	startT = maze.isInputValid(input_x, input_y);
	TrackedRobot t_robot(startT, plate_bottle[1].get());
	maze.changeSpace(t_robot.getRobotLoc(),'t');
	
//	maze.displayMaze();
	
	MobileRobot *tRobot = &t_robot;
	MobileRobot *wRobot = &w_robot;
	
	/*************** Main Code Section: wheeled=plate, tracked=bottle ************************************/
	if (targets_input[0] == 0)
		cout << "\nwheeled=plate, tracked=bottle\n" << endl;
	else
		cout << "\nwheeled=bottle, tracked=plate\n" << endl;
	
	while (maze.isGoal(tRobot,tracked_target)==0) { // This loop will run until the tracked robot reaches its target
		movedPosition = false; // Resets variable that checks if a movement has been made yet
		// -- Looking Up
		if (movedPosition != true) {
			newPosition = t_robot.Up(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
				pastPosSizeT = pastPositionsT.size(); // Update size
				// ------- Update stack with "UP"
				t_robot.setRobotLoc(newPosition); // Update the current position to the new position
				movedPosition = true; // Causes the loop to skip other movements
			}
		}
		// -- Looking Right
		if (movedPosition != true) {
			newPosition = t_robot.Right(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "RIGHT"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Down
		if (movedPosition != true) {
			newPosition = t_robot.Down(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "DOWN"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Left
		if (movedPosition != true) {
			newPosition = t_robot.Left(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "Left"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Backtracking
		if (movedPosition != true) { // If no move can be made
			maze.changeSpace(t_robot.getRobotLoc(),'X'); // Puts an X to mark the wrong path
			for (int i=0; i<pastPosSizeT; ++i) { // Updates current position as last index from pastPositions
				t_robot.setRobotLoc(pastPositionsT[i]);
			}
			pastPositionsT.erase(pastPositionsT.end()); // removes the last movement from pastPositions
			pastPosSizeT = pastPositionsT.size(); // Update size
			// ------- POP out top of the stack
		}
	}
	
	/**********************************************************************/
	while (maze.isGoal(wRobot,wheeled_target)==0) { // This loop will run until the wheeled robot reaches the plate
		movedPosition = false;
		// -- Looking Up
		if (movedPosition != true) {
			newPosition = w_robot.Up(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "UP"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Right
		if (movedPosition != true) {
			newPosition = w_robot.Right(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "RIGHT"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Down
		if (movedPosition != true) {
			newPosition = w_robot.Down(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "DOWN"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Left
		if (movedPosition != true) {
			newPosition = w_robot.Left(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "Left"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Backtracking
		if (movedPosition != true) {
			maze.changeSpace(w_robot.getRobotLoc(),'Y');
			for (int i=0; i<pastPosSizeW; ++i) {
				w_robot.setRobotLoc(pastPositionsW[i]);
			}
			pastPositionsW.erase(pastPositionsW.end());
			pastPosSizeW = pastPositionsW.size();
			// ------- POP out top of the stack
			//	maze.displayMaze();
		}
	}
//	solveMaze(maze, tRobot, wRobot, t_robot, w_robot, tracked_target, wheeled_target, startT, startW, targetP, targetB);
	/***********************************************************************************/
	maze.changeSpace(startW,'w');
	maze.changeSpace(startT,'t');
	maze.changeSpace(targetP,'p');
	maze.changeSpace(targetB,'b');
	
	// Remove X's from Maze
	maze.rewriteX();
	maze.displayMaze();
	return 0;
}

/***********************************************************/
void solveMaze(Maze &maze, MobileRobot* tRobot, MobileRobot* wRobot, TrackedRobot t_robot, WheeledRobot w_robot, vector<int> tracked_target, vector<int> wheeled_target,
							 vector<int> startT, vector<int> startW, vector<int> targetP, vector<int> targetB) {
	while (maze.isGoal(tRobot,tracked_target)==0) { // This loop will run until the tracked robot reaches its target
		movedPosition = false; // Resets variable that checks if a movement has been made yet
		// -- Looking Up
		if (movedPosition != true) {
			newPosition = t_robot.Up(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
				pastPosSizeT = pastPositionsT.size(); // Update size
				// ------- Update stack with "UP"
				t_robot.setRobotLoc(newPosition); // Update the current position to the new position
				movedPosition = true; // Causes the loop to skip other movements
			}
		}
		// -- Looking Right
		if (movedPosition != true) {
			newPosition = t_robot.Right(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "RIGHT"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Down
		if (movedPosition != true) {
			newPosition = t_robot.Down(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "DOWN"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Left
		if (movedPosition != true) {
			newPosition = t_robot.Left(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot);
			if (blocked != true) {
				maze.changeSpace(t_robot.getRobotLoc(),'-');
				pastPositionsT.push_back(t_robot.getRobotLoc());
				pastPosSizeT = pastPositionsT.size();
				// ------- Update stack with "Left"
				t_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Backtracking
		if (movedPosition != true) { // If no move can be made
			maze.changeSpace(t_robot.getRobotLoc(),'X'); // Puts an X to mark the wrong path
			for (int i=0; i<pastPosSizeT; ++i) { // Updates current position as last index from pastPositions
				t_robot.setRobotLoc(pastPositionsT[i]);
			}
			pastPositionsT.erase(pastPositionsT.end()); // removes the last movement from pastPositions
			pastPosSizeT = pastPositionsT.size(); // Update size
			// ------- POP out top of the stack
		}
	}
	
	/**********************************************************************/
	while (maze.isGoal(wRobot,wheeled_target)==0) { // This loop will run until the wheeled robot reaches the plate
		movedPosition = false;
		// -- Looking Up
		if (movedPosition != true) {
			newPosition = w_robot.Up(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "UP"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Right
		if (movedPosition != true) {
			newPosition = w_robot.Right(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "RIGHT"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Down
		if (movedPosition != true) {
			newPosition = w_robot.Down(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "DOWN"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Looking Left
		if (movedPosition != true) {
			newPosition = w_robot.Left(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
			bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot);
			if (blocked != true) {
				maze.changeSpace(w_robot.getRobotLoc(),'|');
				pastPositionsW.push_back(w_robot.getRobotLoc());
				pastPosSizeW = pastPositionsW.size();
				// ------- Update stack with "Left"
				w_robot.setRobotLoc(newPosition);
				movedPosition = true;
			}
		}
		// -- Backtracking
		if (movedPosition != true) {
			maze.changeSpace(w_robot.getRobotLoc(),'Y');
			for (int i=0; i<pastPosSizeW; ++i) {
				w_robot.setRobotLoc(pastPositionsW[i]);
			}
			pastPositionsW.erase(pastPositionsW.end());
			pastPosSizeW = pastPositionsW.size();
			// ------- POP out top of the stack
			//	maze.displayMaze();
		}
	}
	
	maze.changeSpace(startW,'w');
	maze.changeSpace(startT,'t');
	maze.changeSpace(targetP,'p');
	maze.changeSpace(targetB,'b');
	
	// Remove X's from Maze
	maze.rewriteX();
	maze.displayMaze();
//	return maze.maze_arr;
}