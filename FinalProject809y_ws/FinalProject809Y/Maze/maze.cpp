#include <iostream>
#include <fstream>
#include <vector>
#include "maze.h"
#include <string>
using std::cout;

Maze::Maze(std::string filename)
{
	Maze::readMaze(filename);
	displayMaze();
}
 
void Maze::displayMaze() {
  for(auto i:maze_arr) {
    for(auto j:i) {
      std::cout << j;
    }
  }
}

vector< vector<char> > Maze::readMaze(std::string filename) {
  std::ifstream input;
  input.open("filename");
  if (input.is_open()) {
    for (auto i:maze_arr) {
      for (auto j:i) {
        char temp;
		vector< vector<char> > maze_arr[31][46] ;   //declare the variable maze_arr
        temp = input.get();
        maze_arr[i][j] = temp;
      }
    }
  }
  return maze_arr;
}
bool Maze::isInputValid(int start_x , int start_y) {
	while(maze_arr[start_x][start_y]=='#'||start_x<0||start_x>31||start_y<0||start_y>46){
		std::cout<< "Invalid start position. Please enter different coordinates for the start position of the robot:"<<std::endl;
		std::cin >>start_x>>start_y;
	}
	return 0;
}
bool Maze::isTargetValid(int target_x, int target_y, char z) {
	while(maze_arr[target_x][target_y]=='#' || target_x < 0 || target_x > 31 || target_y < 0 || target_y > 46 || maze_arr[target_x][target_y]=='z'){
		std::cout<< "Please enter different coordinates for the target position:"<<std::endl;
		std::cin>>target_x >>target_y ;
	}
	return 0;
}
void Maze::changeSpace(int x, int y, char z){
	maze_arr[x][y] = z;
}	
//void Maze::isWrongPath(int i, int j) 
//{
//	maze_arr[i][j] = 'X'
//}

bool Maze::isObstacle(int x, int y){
	if ((maze_arr[x][y]=='#') || (maze_arr[x][y]=='X')){
		return 1;
	}
	else{
		return 0;
	}
}	

	

Maze::~Maze(){
}

