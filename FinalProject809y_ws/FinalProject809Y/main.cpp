#include <iostream>
#include "Maze/maze.h"
#include <fstream>
#include <vector>


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


size_t width = 31;
size_t length = 46;
char maze_arr[width][length]{0};

int main()
{	//input the maze and ask for start positions
	
	
	cout<<"Please enter the start position for the wheeled robot: "<<endl;  
	// Checking for valid start and goal positions the wheeled robot
	// User inputs for the start position coordinates
	int start_x_wheeled {1};
	int start_y_wheeled {1};
	int start_x_tracked{30};
	int start_y_tracked{1};
	cin >>start_y_wheeled>>start_x_wheeled;						 
	
	// Checking for valid start positions, if not valid, prompts user for different input.
	while(maze_arr[start_x_wheeled][start_y_wheeled]=='#'||start_x_wheeled<0||start_x_wheeled>31||start_y_wheeled<0||start_y_wheeled>46){
		cout<< "Invalid start position. Please enter different coordinates for the start positionof the wheeled robot:"<<endl;
		cin>>start_y_wheeled>>start_x_wheeled;
	}
	cout<<"Please enter the coordinates for the wheeled robot's target (a plate): "<<endl; 
    // Prompts user for the goal position.
	int target_x_wheeled;
	int target_y_wheeled;
	int target_x_tracked;
	int target_y_tracked;
	cin>>target_x_wheeled>>target_y_wheeled;
	
	// Checking for valid target positions, if not valid, prompts user for different input.
	while(maze_arr[target_x_wheeled][target_y_wheeled]!=' ' || target_x_wheeled < 0 || target_x_wheeled > 31 || target_y_wheeled < 0 || target_y_wheeled > 46 ){
		cout<< "Please enter different coordinates for the target position:"<<endl;
		cin>>target_x_wheeled>>target_y_wheeled;
	}
	
	//Now do the same for the tracked robot
	cout<<"Please enter the start position for the tracked robot: "<<endl;  
	// Checking for valid start and goal positions the wheeled robot
	// User inputs for the start position coordinates
	cin>>start_y_tracked>>start_x_tracked;						 
	
	// Checking for valid start positions, if not valid, prompts user for different input.
	while(maze_arr[start_x_tracked][start_y_tracked]!=' ' || start_x_tracked < 0 || start_x_tracked > 31 ||start_y_tracked < 0 || start_y_tracked > 46){
		cout<< "Invalid start position. Please enter different coordinates for the start position of the tracked robot:"<<endl;
		cin>>start_y_tracked>>start_x_tracked;
	}
	cout<<"Please enter the coordinates for the tracked robot's target (a bottle): "<<endl; 
    // Prompts user for the target position.
	cin>>target_x_tracked>>target_y_tracked;
	// Checking for valid target positions, if not valid, prompts user for different input.
	while(maze_arr[target_x_tracked][target_y_tracked]!=' '){
		cout<< "Please enter different coordinates for the target position:"<<endl;
		cin>>target_x_tracked>>target_y_tracked;
	}
	//changeMaze(start_x_wheeled, start_y_wheeled, char 'w' );   //method that changes space in class Maze and adds the correct char
	//changeMaze(start_x_tracked, start_y_tracked, char 't' );
	//changeMaze(target_x_wheeled, target_y_wheeled, char 'p' );
	//changeMaze(target_x_tracked, target_y_tracked, char 'b' );
	return 0;	
}