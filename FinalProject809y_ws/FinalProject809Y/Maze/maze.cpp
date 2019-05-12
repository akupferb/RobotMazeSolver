#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

Maze::Maze(std::string filename)
{
	n = 31;
	m = 46;
	Maze::readMaze(filename);
}

void Maze::readMaze(std::string filename) {
  std::ifstream input;
  input.open(filename);
  if (input.is_open()) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char temp;
        temp = input.get();
        maze_arr[i][j] = temp;
      }
    }
  } else {
    std::cout<<"Invalid Maze File. Terminating"<<std::endl;
    exit(1);
  }
}

void Maze::displayMaze() {
  cout << "\n     ";
  for (int j=0; j<m; ++j)
  cout << j << " ";
  cout << "\n   ---";
  for (int j=0; j<m; ++j)
  cout << "--";
  for (int i=0; i<n; ++i) {
    cout << "\n " << i << " | ";
    for (int j=0; j<m; ++j)
    cout << maze_arr[i][j] << " ";
    cout << "|";
  }
  cout << "\n   ---";
  for (int j=0; j<m; ++j)
  cout << "--";
  cout << endl;
}

bool Maze::isObstacle(int x, int y, MobileRobot robot){
  if( maze_arr[x][y] == '#' || maze_arr[x][y] == robot.wrong_turn || maze_arr[x][y] == robot.visited_marker) {
    return true;
  } else {
    return false;
  }
}

bool Maze::isGoal(MobileRobot robot, Targets goal) {
  if(robot.current_position == goal.position) {
    return true;
  } else {
    return false;
  }
}

std::vector<int> Maze::isTargetInputValid(int start_x, int start_y) {
  while(maze_arr[start_x][start_y]=='#'||start_x<0||start_x>n||start_y<0||start_y>m) {
    std::cout<< "Invalid input position. Please enter different coordinates: "<<std::endl;
    std::cin >>start_x>>start_y;
  }
  std::vector<int> vec;
  vec.push_back(start_x);
  vec.push_back(start_y);
  return vec;
}

void Maze::changeSpace(int x, int y, char z){
	maze_arr[x][y] = z;
}

Maze::~Maze(){
}

