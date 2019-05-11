#ifndef __MAZE_MAZE_H__
#define __MAZE_MAZE_H__
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using std::vector;

class Maze
{
private:
	std::vector<std::vector<char> > maze_arr;
public:
	Maze(std::string filename);
	//attributes
	const int width = 31;
	const int length = 46;
	
	
	//members
	
	void displayMaze();
	vector< vector<char> > readMaze(std::string);
	bool isInputValid(int, int);
	bool isTargetValid(int, int, char);
	void changeSpace(int, int, char);
	//bool isWrongPath(int, int);
	bool isObstacle(int, int);
	~Maze();
};
#endif // __MAZE_MAZE_H__

