#include <vector>
#include "maze.h"
#include <iostream>
#include <fstream>

using std::cout;

 
vector< vector<char> > Maze::displayMaze(int width, int length, string filename)
{
	ifstream input;
	input.open("filename");
	if (input.is_open())
	{
	vector< vector<char> > maze_arr[31][46]{} ;
		for (int i = 0; i <=width-1; i++)
			for (int j=0; j<= length-1; j++)
			{
				char temp;
				temp = input.get();
				maze_arr[i][j] = temp;
				cout << maze_arr[i][j];
	}
void Maze::isWrongPath(int i, int j, <vector<vector<char>> maze_arr) 
{
	maze_arr[i][j] = 'X'
}

bool Maze::isObstacle(int i, int j, <vector<vector<char>> maze_arr)
{
	if (maze_arr[i][j] == "#") ||(maze_arr[i][j] == "X") 
		return 1;
	else
		return 0;	
}

void maze::CanMove()
{
}
	
Maze::Maze()
{
}

Maze::~Maze()
{
}

