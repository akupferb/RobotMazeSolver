#include <iostream>
#include "Maze/maze.h"
#include "RobotModel/TrackedRobot.h"
#include "RobotModel/WheeledRobot.h"
#include <fstream>
#include <vector>
#include <string>

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
	Maze maze_tracked(filename);
	Maze maze_wheeled(filename);
	
	
	// Checking for valid start and target positions for the robots and their targets
	
	std::cout<<"Please enter the start position for the wheeled robot: "<<std::endl;  
	// User inputs for the start position coordinates
	int start_x {1};
	int start_y {1};
	std::cin >>start_x>>start_y;						 
	while (maze_wheeled.isInputValid(start_x, start_y )){  
	}
	
	maze_wheeled.changeSpace(start_x,start_y,'w');
	
	std::cout<<"Please enter the start position for the tracked robot: "<<std::endl;  
	// User inputs for the start position coordinates
	std::cin >>start_x>>start_y;	
					 
	while (maze_tracked.isInputValid(start_x, start_y )){  
	}
	maze_tracked.changeSpace(start_x,start_y,'t');
	
	//User enters target coordinates
	int target_x{1};
	int target_y{1};
	std::cout<<"Please enter the coordinates for the wheeled robot's target (a plate): "<< std::endl;
	std::cin>>target_x>>target_y;
	
	// Checking for valid target positions, if not valid, prompts user for different input.
	while (maze_wheeled.isTargetValid(target_x, target_y, 'w' )){
	}
	maze_wheeled.changeSpace(target_x,target_y,'p');
	
	std::cout<<"Please enter the coordinates for the tracked robot's target (a bottle): "<< std::endl; 
	std::cin>>target_x>>target_y;
	// Checking for valid target positions, if not valid, prompts user for different input.
	while (maze_tracked.isTargetValid(target_x, target_y, 't' )){
	}
	maze_tracked.changeSpace(target_x,target_y,'b');
return 0;
}
