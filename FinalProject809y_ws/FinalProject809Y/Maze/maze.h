#ifndef __MAZE_MAZE_H__
#define __MAZE_MAZE_H__

using namespace std;


class Maze
{
private:
	const int width=31;
	const int length=46;

	
public:
	 
	Maze(const int width, const int length, string filename);  //default constructor 

	void ReadMaze();  		//reads the maze text file into array called maze; only need this once
	
	void updateMaze(int i, int j );  // change the maze array when path changes or robot position changes at position i,j
	 
	void displayMaze(char maze[31][46]);  //displays the maze array
	
	void IsTarget();
	
	void CanMove();
	
	 ~Maze();
	


};



#endif // __MAZE_MAZE_H__
