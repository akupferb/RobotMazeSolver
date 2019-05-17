#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

Maze::Maze() {
	n = 31;
	m = 46;
}

bool Maze::isObstacle(int x, int y, MobileRobot* robot) {
	if ( maze_arr[x][y] == '#' || maze_arr[x][y] == robot->getWrongTurnMarker() || maze_arr[x][y] == robot->getVisitedMarker())
		return true;
	if ( maze_arr[x][y] == '+' || maze_arr[x][y] == 'T' || maze_arr[x][y] == 'Z' || x>=n)
		return true;
	return false;
}

bool Maze::isGoal(MobileRobot* robot, std::vector<int> goal) {
	if(robot->getRobotLoc() == goal) {
		return true;
	} else {
		return false;
	}
}

std::vector<int> Maze::isInputValid(int x, int y) {
	while( maze_arr[x][y]=='#' || x<0 || x>=n || y<0 || y>=m ) {
		cout<< "Invalid input, position is obstacle or outside maze. Please enter different coordinates: ";
		cin >> x >> y;
	}
	std::vector<int> vec;
	vec.push_back(x);
	vec.push_back(y);
	return vec;
}

/**
* The many "if" statements in this function account for the different possible characters that can already occupy
* the space to be overwritten. If it's part of the robot's path, and the other robot has crossed that path, a '+' 
* is used. If the robot is backtracking, and the other robot has crossed that path, a 'T' is used. If both robots
* have backtracked, a 'Z' is used. If both robot start positions are the same, an 'S' is used, and if the targets
* are the same, a 'G' is used. These conditions ensure that the second robot does not erase the first robot's path.
*/
void Maze::changeSpace(std::vector<int> xy, char z) {
	int x = xy[0]; int y = xy[1];
	if (z=='|') {
		if (maze_arr[x][y] == '-')
			maze_arr[x][y] = '+';
		else if (maze_arr[x][y] == '+')
			maze_arr[x][y] = '+';
		else
			maze_arr[x][y] = z;
	}
	else if (z=='Y') {
		if (maze_arr[x][y] == '-' || maze_arr[x][y] == '+')
			maze_arr[x][y] = 'T';
		else if (maze_arr[x][y] == 'X')
			maze_arr[x][y] = 'Z';
		else 
			maze_arr[x][y] = z;
	}
	else if (z=='w') {
		if (maze_arr[x][y] == 't')
			maze_arr[x][y] = 'S';
		else
			maze_arr[x][y] = z;
	}
	else if (z=='b') {
		if (maze_arr[x][y] == 'p')
			maze_arr[x][y] = 'G';
		else
			maze_arr[x][y] = z;
	}
	else
		maze_arr[x][y] = z;
}

/**
* The function looks for any of the three markers that represent only a wrong turn space, and replaces that 
* character with an open space. If a 'T' if found, that means that it is a right path for the tracked robot
* and wrong turn for the wheeled robot, so the tracked robot path character '-' is replaced. Finally, the 
* start positions of the robots, and the target positions are placed in at the end.
*/
void Maze::rewrite(MobileRobot* robot, MobileRobot* robot2, std::vector<int> plate, std::vector<int> bottle) {
	for (int i=0; i<31; i++) {
		for (int j=0; j<46; j++) {
			if (maze_arr[i][j] == 'X' || maze_arr[i][j] == 'Y' || maze_arr[i][j] == 'Z')
				 maze_arr[i][j] = ' ';
			if (maze_arr[i][j] == 'T')
				 maze_arr[i][j] = '-';
		}
	}
	changeSpace(robot->getStart(),robot->getStartMarker());
	changeSpace(robot2->getStart(),robot2->getStartMarker());
	changeSpace(plate,'p');
	changeSpace(bottle,'b');
}

void Maze::displayMaze() {
	cout << "\n    ---";
	for (int j=0; j<m; ++j)
		cout << "--";
	for (int i=0; i<n; ++i) {
		if (i<10)
			cout << "\n  " << i << " | ";
		else
			cout << "\n " << i << " | ";
		for (int j=0; j<m; ++j)
			cout << maze_arr[i][j] << " ";
		cout << "|";
	}
	cout << "\n    ---";
	for (int j=0; j<m; ++j)
		cout << "--";
	cout << "\n      ";
	int h = 0; int k = 1;
	for (int j=0; j<m; ++j) {
		if (j<10)
			cout << j << " ";
		else {
			if (h==10) {
				k++;
				h=0;
			}
			cout << k << " ";
			h++;
		}
	}
	cout << "\n                          ";
	for (int i=0; i<3; i++) {
		for (int j=0; j<10; j++)
			cout << j << " ";
	}
	cout << "0 1 2 3 4 5";
	cout << endl;
}

std::vector<int> Maze::numericInputs() {
	int input1, input2;
	cin >> input1 >> input2;
	while(!cin) {
		cin.clear(); // reset failbit
		cin.ignore(1000,'\n'); //skip bad input
		cout << "Invalid Entry, non-numeric input. Please reenter the two inputs: ";
		cin >> input1 >> input2;
	}
	std::vector<int> inputs;
	inputs = isInputValid(input1, input2);
	cout << "[" << inputs[0] << "," << inputs[1] << "]" << endl;
	return inputs;
}
