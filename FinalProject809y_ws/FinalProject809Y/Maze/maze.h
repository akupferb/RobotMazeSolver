#ifndef __MAZE_MAZE_H__
#define __MAZE_MAZE_H__

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"

using std::vector;

class Maze
{
private:
	char maze_arr[31][46];
	int n;
	int m;
	std::vector<int> start_position;
public:
	Maze(std::string);
	// Methods
	void readMaze(std::string);
	void displayMaze();
	bool isObstacle(int, int, MobileRobot);
	bool isGoal(MobileRobot, Targets);
	std::vector<int> isTargetInputValid(int, int);
	void changeSpace(int, int, char);
	~Maze();
};
#endif // __MAZE_MAZE_H__

