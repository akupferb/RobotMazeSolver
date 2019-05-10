#include "maze.h"
#include <iostream>
#include <fstream>

using namespace std;

Maze::Maze(const int width, const int length, string filename) ;
{
	ifstream input;
	input.open("../maze.txt");
	if (input.is_open())
	{
		for (int i = 0; i <=width; i++)
			for (int j=0; j<= length; j++)
			{
				char temp;
				temp = input.get();
				maze[i][j] = temp;
			}
		input.close();
	}
	return Maze;
	
}
 
void Maze::displayMaze()
{
	for (int i=0; i<width; i++){ 
		if (i == 0){
			cout<<"\n";
			cout << i << " | ";
			for (int j=0; j<length; j++){
			cout << maze[i][j]; // This loop displayes the actual maze characters
			}
			
		}
		else if (i > 0 && i <=9){
			cout <<"\n" <<i<< " | " ;		// 
			for (int j=0; j<length; j++){
				cout << maze[i][j]; // This loop displayes the actual maze characters
			} 
		}
		else{
			cout << i<<"| ";
			for (int j=0; j<length; j++){
				cout << maze[i][j]; // This loop displayes the actual maze characters
			}
		}
		
	}
}
}

void Maze::IsTarget()
{
}

void Maze::CanMove()
{
}
