#include <iostream>
#include "Maze/maze.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
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
{	//input the maze and ask for start positions
	std::string filename= "../maze.txt";
	Maze maze(filename);
	std::vector<int> start;
	int input;
	int input_x, input_y;
	std::vector<int> robot_targets;
	/***************************************************************/
	cout << "Please enter target choice for wheeled robot (0 for plate, 1 for bottle): " << endl;
	cin >> input;
	robot_targets.push_back(input);
	if(input == 1){
		robot_targets.push_back(0);
	} else {
		robot_targets.push_back(1);
	}
	/*********************************************************************/
	cout << "Please enter the coordinates for the plate target: " << endl;
	cin >> input_x >> input_y;
	start = maze.isTargetInputValid(input_x, input_y);
	maze.changeSpace(input_x, input_y,'p');
	Targets plate(start);
	/*********************************************************************/
	cout << "Please enter the coordinates for the bottle target: " << endl;
	cin >> input_x >> input_y;
	start = maze.isTargetInputValid(input_x, input_y);
	maze.changeSpace(input_x, input_y,'b');
	Targets bottle(start);
	/*********************************************************************/
	cout << "Please enter the start position for the wheeled robot: " << endl;
	cin >> input_x >> input_y;
	if(robot_targets[0] == 0) {
		WheeledRobot w_robot(input_x, input_y, plate);
	} else {
		WheeledRobot w_robot(input_x, input_y, bottle);
	}
	/*********************************************************************/
	cout << "Please enter the start position for the tracked robot: " << endl;
	cin >> input_x >> input_y;
	if(robot_targets[0] == 1) {
		TrackedRobot t_robot(input_x, input_y, plate);
	} else {
		TrackedRobot t_robot(input_x, input_y, bottle);
	}
	
	vector <vector<int>> pastPositions;
	int pastPosSize = pastPositions.size();
	bool movedPosition;
	vector<int> newPosition;
	
	/*************** Main Code Section ************************************/
	if (robot_targets[0] == 1)
		while (maze.isGoal(t_robot,bottle)) { // This loop will run until the tracked robot reaches the bottle
			movedPosition = false; // Resets variable that checks if a movement has been made yet
			
			// -- Looking North
			if (movedPosition != true) {
				newPosition = t_robot.Up(t_robot.current_position[0],t_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
				if (blocked == false) {
					t_robot.MovedUp(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.current_position;
					// ------- Update stack with "UP"
					t_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Looking East
			if (movedPosition != true) {
				newPosition = t_robot.Right(t_robot.current_position[0],t_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
				if (blocked == false) {
					t_robot.MovedRight(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.current_position;
					// ------- Update stack with "RIGHT"
					t_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking South
			if (movedPosition != true) {
				newPosition = t_robot.Down(t_robot.current_position[0],t_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
				if (blocked == false) {
					t_robot.MovedDown(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.current_position;
					// ------- Update stack with "DOWN"
					t_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking west
			if (movedPosition != true) {
				newPosition = t_robot.Left(t_robot.current_position[0],t_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],t_robot); // (checks for #, X, -)
				if (blocked == false) {
					t_robot.MovedLeft(newPosition[0],newPosition[1]);
					pastPositions.push_back(t_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.current_position;
					// ------- Update stack with "Left"
					t_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Backtracking
			if (movedPosition != true) { // If no move can be made
	//			cout << "-----we must backtrack :(" << endl;
				//vector<int> temp = t_robot.current_position; // Saves the current position in a temporary variable
				maze.changeSpace(t_robot.current_position[0],t_robot.current_position[1],'X')
				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
					t_robot.current_position[0] = pastPositions[i][0]; t_robot.current_position[1] = pastPositions[i][1];
				}
				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
				pastPosSize = pastPositions.size();
				// ------- POP out top of the stack
				//previousPosition = temp;
	//			cout << "[" << currentPosT[0] << "," << currentPosT[1] << "]" << endl;
			}
		}
		
		while (maze.isGoal(w_robot,bottle)) { // This loop will run until the wheeled robot reaches the plate
			movedPosition = false; // Resets variable that checks if a movement has been made yet
			
			// -- Looking North
			if (movedPosition != true) {
				newPosition = w_robot.Up(w_robot.current_position[0],w_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
				if (blocked == false) {
					w_robot.MovedUp(newPosition[0],newPosition[1]);
					pastPositions.push_back(w_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = w_robot.current_position;
					// ------- Update stack with "UP"
					w_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Looking East
			if (movedPosition != true) {
				newPosition = w_robot.Right(w_robot.current_position[0],w_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
				if (blocked == false) {
					w_robot.MovedRight(newPosition[0],newPosition[1]);
					pastPositions.push_back(w_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = w_robot.current_position;
					// ------- Update stack with "RIGHT"
					w_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking South
			if (movedPosition != true) {
				newPosition = w_robot.Down(w_robot.current_position[0],w_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
				if (blocked == false) {
					w_robot.MovedDown(newPosition[0],newPosition[1]);
					pastPositions.push_back(w_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = w_robot.current_position;
					// ------- Update stack with "DOWN"
					w_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
		
			// -- Looking west
			if (movedPosition != true) {
				newPosition = w_robot.Left(w_robot.current_position[0],w_robot.current_position[1]);
				bool blocked = maze.isObstacle(newPosition[0],newPosition[1],w_robot); // (checks for #, X, -)
				if (blocked == false) {
					w_robot.MovedLeft(newPosition[0],newPosition[1]);
					pastPositions.push_back(w_robot.current_position); // Add current position to pastPositions 2D vector
					pastPosSize = pastPositions.size(); // Update size
					//previousPosition = t_robot.current_position;
					// ------- Update stack with "Left"
					w_robot.current_position = newPosition; // Update the current position to the new position
					movedPosition = true; // Causes the loop to skip other movements
				}
			}
			
			// -- Backtracking
			if (movedPosition != true) { // If no move can be made
	//			cout << "-----we must backtrack :(" << endl;
				//vector<int> temp = t_robot.current_position; // Saves the current position in a temporary variable
				maze.changeSpace(w_robot.current_position[0],w_robot.current_position[1],'Y')
				for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
					t_robot.current_position[0] = pastPositions[i][0]; t_robot.current_position[1] = pastPositions[i][1];
				}
				pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
				pastPosSize = pastPositions.size();
				// ------- POP out top of the stack
				//previousPosition = temp;
	//			cout << "[" << currentPosT[0] << "," << currentPosT[1] << "]" << endl;
			}
		}
	}
	return 0;
}
