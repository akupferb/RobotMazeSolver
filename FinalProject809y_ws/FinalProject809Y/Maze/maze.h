#ifndef __MAZE_MAZE_H__
#define __MAZE_MAZE_H__
#include <vector>
#include "maze.h"
#include <iostream>
#include <fstream>
using namespace std;

class Maze
{
public:
	Maze();
	vector <vector<char> > displayMaze(int width, int length, string filename);
	
	bool IsWrongPath(int i, int j, vector< vector<char> > maze_arr);
	bool isObstacle(int i, int j, vector< vector<char> > maze_arr);
	~Maze();
#endif // __MAZE_MAZE_H__
