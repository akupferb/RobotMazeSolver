#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
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

std::vector<int> Maze::isInputValid(int start_x, int start_y) {
	while(maze_arr[start_x][start_y]=='#'||start_x<0||start_x>=n||start_y<0||start_y>=m) {
		std::cout<< "Invalid input position. Please enter different coordinates: ";
		std::cin>>start_x>>start_y;
	}
	std::vector<int> vec;
	vec.push_back(start_x);
	vec.push_back(start_y);
	return vec;
}

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

void Maze::rewriteX(MobileRobot* robot, MobileRobot* robot2, std::vector<int> p, std::vector<int> b) {
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
	changeSpace(p,'p');
	changeSpace(b,'b');
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
	std::cin >> input1 >> input2;
	while(!std::cin) {
		std::cin.clear(); // reset failbit
		std::cin.ignore(1000,'\n'); //skip bad input
		std::cout << "Invalid Entry, non-numeric input. Please reenter the two inputs: ";
		std::cin >> input1 >> input2;
	}
	std::vector<int> inputs;
	inputs = isInputValid(input1, input2);
	std::cout << "[" << inputs[0] << "," << inputs[1] << "]" << std::endl;
	return inputs;
}
