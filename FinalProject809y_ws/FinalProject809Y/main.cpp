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

int main()
{
//	std::string filename = "../maze.txt";
	Maze maze;
	std::vector<int> startT;
	std::vector<int> startW;
	std::vector<int> targetP;
	std::vector<int> targetB;
	int input;
	int input_x, input_y;
	std::vector<int> robot_targets;
	std::vector<Targets> plate_bottle;
	/***************************************************************/
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): ";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Invalid entry! Please enter only 0 or 1: ";
		cin >> input;
	}
	robot_targets.push_back(input);
	if(input == 1){
		robot_targets.push_back(0);
	} else {
		robot_targets.push_back(1);
	}
	/*********************************************************************/
	cout << "Please enter the coordinates for the plate target: ";
	cin >> input_x >> input_y;
	targetP = maze.isInputValid(input_x, input_y);
	input_x = targetP[0]; input_y = targetP[1];
	maze.changeSpace(input_x, input_y,'p');
//	cout << "[" << input_x << " " << input_y << "]" <<  endl;
	Targets plate(targetP);
	/*********************************************************************/
	cout << "Please enter the coordinates for the bottle target: ";
	cin >> input_x >> input_y;
	targetB = maze.isInputValid(input_x, input_y); 
	input_x = targetB[0]; input_y = targetB[1];
	maze.changeSpace(input_x, input_y,'b');
//	cout << "[" << input_x << " " << input_y << "]" <<  endl;
	Targets bottle(targetB);
	/*********************************************************************/
	if(robot_targets[0] == 0) {
		plate_bottle.push_back(plate);
		plate_bottle.push_back(bottle);
	} else {
		plate_bottle.push_back(bottle);
		plate_bottle.push_back(plate);
	}
	/*********************************************************************/
	cout << "Please enter the start position for the wheeled robot: ";
	cin >> input_x >> input_y;
	startW = maze.isInputValid(input_x, input_y); 
	input_x = startW[0]; input_y = startW[1];
	WheeledRobot w_robot(input_x, input_y, plate_bottle[0].get());
	input_x = w_robot.getRobotLoc()[0]; input_y = w_robot.getRobotLoc()[1];
	maze.changeSpace(input_x, input_y,'w');
//	cout << "[" << input_x << " " << input_y << "]" <<  endl;
	/*********************************************************************/
	cout << "Please enter the start position for the tracked robot: ";
	cin >> input_x >> input_y;
	startT = maze.isInputValid(input_x, input_y); 
	input_x = startT[0]; input_y = startT[1];
	TrackedRobot t_robot(input_x, input_y, plate_bottle[1].get());
	input_x = t_robot.getRobotLoc()[0]; input_y = t_robot.getRobotLoc()[1];
	maze.changeSpace(input_x, input_y,'t');
//	cout << "[" << input_x << " " << input_y << "]" <<  endl;
	
	maze.displayMaze();
	vector <vector<int>> pastPositions;
	int pastPosSize = pastPositions.size();
	bool movedPosition;
	vector<int> newPosition;
	
	MobileRobot *tRobot = &t_robot;
//	MobileRobot *wRobot = &w_robot;
	
	/*************** Main Code Section: tracked=bottle, wheeled=plate ************************************/
	if (robot_targets[0] == 0) {
		cout << "tracked=bottle, wheeled=plate" << endl;
		while (maze.isGoal(tRobot,targetB)==0) { // This loop will run until the tracked robot reaches the bottle
			movedPosition = false; // Resets variable that checks if a movement has been made yet
			
			// -- Looking North
			if (movedPosition != true) {
				newPosition = t_robot.Up(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
				if (blocked != true) {
//				cout << "[" << newPosition[0] << " " << newPosition[1] << "]" <<  endl;
					maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'-'); //t_robot.MovedUp(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.getRobotLoc();
					// ------- Update stack with "UP"
					t_robot.setRobotLoc(newPosition); // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Looking East
			if (movedPosition != true) {
				newPosition = t_robot.Right(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				cout << "[" << newPosition[0] << " " << newPosition[1] << "]" <<  endl;
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
				if (blocked != true) {
					maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'-'); //t_robot.MovedRight(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.getRobotLoc();
					// ------- Update stack with "RIGHT"
					t_robot.setRobotLoc(newPosition); // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking South
			if (movedPosition != true) {
				newPosition = t_robot.Down(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				cout << "[" << newPosition[0] << " " << newPosition[1] << "]" <<  endl;
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
				if (blocked != true) {
					maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'-'); //t_robot.MovedDown(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.getRobotLoc();
					// ------- Update stack with "DOWN"
					t_robot.setRobotLoc(newPosition); // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking west
			if (movedPosition != true) {
				newPosition = t_robot.Left(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				cout << "[" << newPosition[0] << " " << newPosition[1] << "]" <<  endl;
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],tRobot); // (checks for #, X, -)
				if (blocked != true) {
					maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'-'); //t_robot.MovedLeft(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.getRobotLoc();
					// ------- Update stack with "Left"
					t_robot.setRobotLoc(newPosition); // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Backtracking
			if (movedPosition != true) { // If no move can be made
	//			cout << "-----we must backtrack :(" << endl;
				//vector<int> temp = t_robot.getRobotLoc(); // Saves the current position in a temporary variable
				maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'X');
				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
					t_robot.setRobotLoc(pastPositions[i]);
				}
				
				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
				pastPosSize = pastPositions.size();
				// ------- POP out top of the stack
				//previousPosition = temp;
			}
		}
		
//		while (maze.isGoal(wRobot,targetP)==0) { // This loop will run until the wheeled robot reaches the plate
//			movedPosition = false; // Resets variable that checks if a movement has been made yet
//			
//			// -- Looking North
//			if (movedPosition != true) {
//				newPosition = w_robot.Up(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot); // (checks for #, X, -)
//				if (blocked == false) {
//					maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'|'); //w_robot.MovedUp(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "UP"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Looking East
//			if (movedPosition != true) {
//				newPosition = w_robot.Right(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot); // (checks for #, X, -)
//				if (blocked == false) {
//					maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'|'); //w_robot.MovedRight(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "RIGHT"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking South
//			if (movedPosition != true) {
//				newPosition = w_robot.Down(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot); // (checks for #, X, -)
//				if (blocked == false) {
//					maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'|'); //w_robot.MovedDown(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "DOWN"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking west
//			if (movedPosition != true) {
//				newPosition = w_robot.Left(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],wRobot); // (checks for #, X, -)
//				if (blocked == false) {
//					maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'|'); //w_robot.MovedLeft(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "Left"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Backtracking
//			if (movedPosition != true) { // If no move can be made
//	//			cout << "-----we must backtrack :(" << endl;
//				//vector<int> temp = t_robot.getRobotLoc(); // Saves the current position in a temporary variable
//				maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'Y');
//				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
//					t_robot.getRobotLoc()[0] = pastPositions[i][0]; t_robot.getRobotLoc()[1] = pastPositions[i][1];
//				}
//				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
//				pastPosSize = pastPositions.size();
//				// ------- POP out top of the stack
//				//previousPosition = temp;
//			}
//		}
	}
	
//	/*************** Main Code Section: tracked=plate, wheeled=bottle ************************************/
//	if (robot_targets[0] == `) {
//		while (maze.isGoal(t_robot,plate)) { // This loop will run until the tracked robot reaches the plate
//			movedPosition = false; // Resets variable that checks if a movement has been made yet
//			
//			// -- Looking North
//			if (movedPosition != true) {
//				newPosition = t_robot.Up(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					t_robot.MovedUp(newPosition[0],newPosition[1]);
//					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "UP"
//					t_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Looking East
//			if (movedPosition != true) {
//				newPosition = t_robot.Right(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					t_robot.MovedRight(newPosition[0],newPosition[1]);
//					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "RIGHT"
//					t_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking South
//			if (movedPosition != true) {
//				newPosition = t_robot.Down(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					t_robot.MovedDown(newPosition[0],newPosition[1]);
//					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "DOWN"
//					t_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking west
//			if (movedPosition != true) {
//				newPosition = t_robot.Left(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					t_robot.MovedLeft(newPosition[0],newPosition[1]);
//					pastPositions.push_back(t_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "Left"
//					t_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Backtracking
//			if (movedPosition != true) { // If no move can be made
//	//			cout << "-----we must backtrack :(" << endl;
//				//vector<int> temp = t_robot.getRobotLoc(); // Saves the current position in a temporary variable
//				maze.changeSpace(t_robot.getRobotLoc()[0],t_robot.getRobotLoc()[1],'X')
//				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
//					t_robot.getRobotLoc()[0] = pastPositions[i][0]; t_robot.getRobotLoc()[1] = pastPositions[i][1];
//				}
//				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
//				pastPosSize = pastPositions.size();
//				// ------- POP out top of the stack
//				//previousPosition = temp;
//			}
//		}
//		
//		while (maze.isGoal(w_robot,bottle)) { // This loop will run until the wheeled robot reaches the bottle
//			movedPosition = false; // Resets variable that checks if a movement has been made yet
//			
//			// -- Looking North
//			if (movedPosition != true) {
//				newPosition = w_robot.Up(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					w_robot.MovedUp(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "UP"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Looking East
//			if (movedPosition != true) {
//				newPosition = w_robot.Right(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					w_robot.MovedRight(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "RIGHT"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking South
//			if (movedPosition != true) {
//				newPosition = w_robot.Down(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					w_robot.MovedDown(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = w_robot.getRobotLoc();
//					// ------- Update stack with "DOWN"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//		
//			// -- Looking west
//			if (movedPosition != true) {
//				newPosition = w_robot.Left(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1]);
//				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
//				if (blocked == false) {
//					w_robot.MovedLeft(newPosition[0],newPosition[1]);
//					pastPositions.push_back(w_robot.getRobotLoc()); // Add current position to pastPositions 2D vector
//					pastPosSize = pastPositions.size(); // Update size
//					//previousPosition = t_robot.getRobotLoc();
//					// ------- Update stack with "Left"
//					w_robot.getRobotLoc() = newPosition; // Update the current position to the new position
//					movedPosition = true; // Causes the loop to skip other movements
//				}
//			}
//			
//			// -- Backtracking
//			if (movedPosition != true) { // If no move can be made
//	//			cout << "-----we must backtrack :(" << endl;
//				//vector<int> temp = t_robot.getRobotLoc(); // Saves the current position in a temporary variable
//				maze.changeSpace(w_robot.getRobotLoc()[0],w_robot.getRobotLoc()[1],'Y')
//				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
//					t_robot.getRobotLoc()[0] = pastPositions[i][0]; t_robot.getRobotLoc()[1] = pastPositions[i][1];
//				}
//				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
//				pastPosSize = pastPositions.size();
//				// ------- POP out top of the stack
//				//previousPosition = temp;
//			}
//		}
//	}
	
	/***********************************************************************************/
//	delete tRobot;
//	delete wRobot;
	maze.changeSpace(startT[0],startT[1],'t');
	for (int i=0; i<31; i++) {
		for (int j=0; j<46; j++) {
			if (maze.maze_arr[i][j] == 'X')
				maze.changeSpace(i,j,' ');
		}
	}
//	Maze * pointMaze = &maze;
//	maze.rewriteX(pointMaze);
	maze.displayMaze();
	return 0;
}
