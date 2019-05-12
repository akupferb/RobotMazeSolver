// Written by: Ari Kupferberg, 03/13/2019

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBlocked(vector<int>, vector<vector<int>>, size_t);
vector <int> startPos(vector<vector<int>>, int);
vector <int> goNorth(vector<int>);
vector <int> goEast(vector<int>);
vector <int> goSouth(vector<int>);
vector <int> goWest(vector<int>);
void displayMaze();

/* 
 Some Maze Designs:

   * 0 1 2 3 4 5 *   * 0 1 2 3 4 5 *   * 0 1 2 3 4 5 * 
 * |-------------| * |-------------| * |-------------| * 
 0 | . . . # # . | * | . # # # # # | * | . # # . . # | 0 
 1 | . # . # # . | * | . # . . . # | * | . . # . # . | 1 
 2 | . # . # # . | * | . # . # . # | * | # . . . # . | 2 
 3 | . # . # # . | * | . # . # . # | * | . . # # . . | 3 
 4 | . # . # # . | * | . # # # . # | * | . # . . . # | 4 
 5 | . # . . . . | * | . . . . . # | * | . . . # . . | 5 
 * |-------------| * |-------------| * |-------------|
                         
   * 0 1 2 3 4 5 6 7 8 9 *
 * |---------------------|
 0 | . . . # . . . # # . |
 1 | . # . . . # . . # . |
 2 | . # . # # . # . . . |
 3 | # . . . # . . . # # |
 4 | # # . # . # . # . # |
 5 | . . . . . # . . . G |
 * |---------------------|
           Current
 */
 
const int n = 6, m = 10; // Variables that define the size of the maze (6x6)
string maze[n][m] { // Defined maze
	{"." , "." , "." , "#" , "." , "." , "." , "#" , "#" , "."} ,
	{"." , "#" , "." , "." , "." , "#" , "." , "." , "#" , "."} ,
	{"." , "#" , "." , "#" , "#" , "." , "#" , "." , "." , "."} ,
	{"#" , "." , "." , "." , "#" , "." , "." , "." , "#" , "#"} ,
	{"#" , "#" , "." , "#" , "." , "#" , "." , "#" , "." , "#"} ,
	{"." , "." , "." , "." , "." , "#" , "." , "." , "." , "G"}
};

// Char version of maze:
//	{'.' , '.' , '.' , '#' , '.' , '.' , '.' , '#' , '#' , '.'} ,
//	{'.' , '#' , '.' , '.' , '.' , '#' , '.' , '.' , '#' , '.'} ,
//	{'.' , '#' , '.' , '#' , '#' , '.' , '#' , '.' , '.' , '.'} ,
//	{'#' , "." , '.' , '.' , '#' , '.' , '.' , '.' , '#' , '#'} ,
//	{'#' , '#' , '.' , '#' , '.' , '#' , '.' , '#' , '.' , '#'} ,
//	{'.' , '.' , '.' , '.' , '.' , '#' , '.' , '.' , '.' , "."}

int main()
{
	vector <vector<int>> obstacles{}; // The vector used to store the obstacle positions
	vector <int> obstacleIndex{0,0}; // The row vector used to add each obstacle's row+column index
	vector<int> goalPosition{0,0}; // The row vector used to store the goal position
	
	// Using a 'for' loop to store the obstacle positions:
	for (int i=0; i < n; ++i) {
		for (int j=0; j < m; ++j) {
			if (maze[i][j] == "#") { // If this position contains an obstacle
				obstacleIndex[0] = i; obstacleIndex[1] = j;
				obstacles.push_back(obstacleIndex); // Adds current position index to vector
			}
			if (maze[i][j] == "G") {
				goalPosition[0] = i; goalPosition[1] = j; // Sets the goal position in the maze
			}
		}
	}
	int numObstacles = obstacles.size();
//	for (int i=0; i<numObstacles; i++) {
//		cout << "[" << obstacles[i][0] << "," << obstacles[i][1] << "]" << endl;
//	}
	displayMaze();
	
	vector <vector<int>> pastPositions;
	int pastPosSize = pastPositions.size();
	vector <vector<int>> wrongPath;
	int wrongPathSize = wrongPath.size();
	bool movedPosition;
	
	int xS,yS;
	vector<int> startingPosition{0,0};
	startingPosition = startPos(obstacles, numObstacles);
	xS = startingPosition[0]; yS = startingPosition[1];
	
	vector<int> currentPosition = startingPosition;
	vector<int> previousPosition = currentPosition;
	
	vector<int> newPosition;
	
	//findPath
	
	while (currentPosition != goalPosition) { // This loop will run until the robot reaches the goal
		movedPosition = false; // Resets variable that checks if a movement has been made yet
		
		// -- Looking North
		if (currentPosition.at(0) > 0 && movedPosition != true) {
			newPosition = goNorth(currentPosition);
			bool a = isBlocked(newPosition,obstacles,numObstacles);
			bool b = isBlocked(newPosition,pastPositions,pastPosSize);
			bool c = isBlocked(newPosition,wrongPath,wrongPathSize);
			if (newPosition != previousPosition && a == false && b == false && c == false) {
				pastPositions.push_back(currentPosition); // Add current position to pastPositions 2D vector
				pastPosSize = pastPositions.size(); // Update size
				previousPosition = currentPosition;
				currentPosition = newPosition; // Update the current position to the new position
				movedPosition = true; // Causes the loop to skip other movements
			}
		}
		
		// -- Looking East
		if (currentPosition.at(1) < m-1 && movedPosition != true) {
			newPosition = goEast(currentPosition);
			bool a = isBlocked(newPosition,obstacles,numObstacles);
			bool b = isBlocked(newPosition,pastPositions,pastPosSize);
			bool c = isBlocked(newPosition,wrongPath,wrongPathSize);
			if (newPosition != previousPosition && a == false && b == false && c == false) {
				pastPositions.push_back(currentPosition);
				pastPosSize = pastPositions.size();
				previousPosition = currentPosition;
				currentPosition = newPosition;
				movedPosition = true;
			}
		}
	
		// -- Looking South
		if (currentPosition.at(0) < n-1 && movedPosition != true) {
			newPosition = goSouth(currentPosition);
			bool a = isBlocked(newPosition,obstacles,numObstacles);
			bool b = isBlocked(newPosition,pastPositions,pastPosSize);
			bool c = isBlocked(newPosition,wrongPath,wrongPathSize);
			if (newPosition != previousPosition && a == false && b == false && c == false) {
				pastPositions.push_back(currentPosition);
				pastPosSize = pastPositions.size();
				previousPosition = currentPosition;
				currentPosition = newPosition;
				movedPosition = true;
			}
		}
	
		// -- Looking west
		if (currentPosition.at(1) > 0 && movedPosition != true) {
			newPosition = goWest(currentPosition);
			bool a = isBlocked(newPosition,obstacles,numObstacles);
			bool b = isBlocked(newPosition,pastPositions,pastPosSize);
			bool c = isBlocked(newPosition,wrongPath,wrongPathSize);
			if (newPosition != previousPosition && a == false && b == false && c == false) {
				pastPositions.push_back(currentPosition);
				pastPosSize = pastPositions.size();
				previousPosition = currentPosition;
				currentPosition = newPosition;
				movedPosition = true;
			}
		}
		
		// -- Backtracking
		if (movedPosition != true) { // If no move can be made
//			cout << "-----we must backtrack :(" << endl;
			vector<int> temp = currentPosition; // Saves the current position in a temporary variable
			wrongPath.push_back(currentPosition); // Add current position to wrongPath 2D vector
			wrongPathSize = wrongPath.size(); // Update size
			for (int i=0; i<pastPosSize; ++i) { // Updates current position as last index from pastPositions
				currentPosition[0] = pastPositions[i][0]; currentPosition[1] = pastPositions[i][1];
			}
			pastPositions.erase(pastPositions.end()); // remove the last movement from pastPositions
			pastPosSize = pastPositions.size();
			previousPosition = temp;
//			cout << "[" << currentPosition[0] << "," << currentPosition[1] << "]" << endl;
		}
	}
	int xG = currentPosition[0]; int yG = currentPosition[1];
	cout << "We have reached the goal!" << endl;
	
	for (int i=1; i<pastPosSize; ++i) { // Replace every moved position in the maze with a '+'
		int x = pastPositions[i][0];
		int y = pastPositions[i][1];
		maze[x][y] = "+";
	}
	maze[xS][yS] = "S"; // Replace starting position in maze with a 'S'
	maze[xG][yG] = "G"; // Replace goal position in maze with a 'G'
	
	cout << "\nThe maze path is:\n";
	for (int i=0; i<pastPosSize; ++i) // Loops through all past positions to display direct maze path
		cout << "[" << pastPositions[i][0] << "," << pastPositions[i][1] << "]" << endl;
	cout << "[" << currentPosition[0] << "," << currentPosition[1] << "]" << endl;
	
	displayMaze();
	cout << "\n";
	return 0;
}

vector <int> startPos(vector<vector<int>>obstacles, int numObstacles) {
	int xS,yS;
	vector<int> startingPosition{0,0};
	cout << "Input starting position (x y): ";
	cin >> xS >> yS;
	startingPosition[0] = xS; startingPosition[1] = yS;
	bool s = isBlocked(startingPosition,obstacles,numObstacles);
	while (s == true) { // check if chosen position is an obstacle
		cout << "\nThere is an obstacle in that position.\n";
		cout << "Select a different starting position (x y): ";
		cin >> xS >> yS;
		startingPosition[0] = xS; startingPosition[1] = yS;
		s = isBlocked(startingPosition,obstacles,numObstacles);
	}
	while (xS < 0 || xS >= n || yS < 0 || yS >= m) { // Check if chosen position is outside the maze
		cout << "\nThat position is out of bounds.\n";
		cout << "Select a different starting position (x y): ";
		cin >> xS >> yS;
		startingPosition[0] = xS; startingPosition[1] = yS;
	}
	return startingPosition;
}

bool isBlocked(vector<int> cPos, vector<vector<int>> obs, size_t size) {
	for (size_t i=0; i < size; ++i) {
		if (cPos[0] == obs[i][0] && cPos[1] == obs[i][1])
			return true;
	}
	return false;
}


vector <int> goNorth(vector<int> cPos) {
	int x = cPos[0];
	int y = cPos[1];
	vector <int> nPos;
	nPos.push_back(x-1);
	nPos.push_back(y);
	return nPos;
}

vector <int> goEast(vector<int> cPos) {
	int x = cPos[0];
	int y = cPos[1];
	vector <int> nPos;
	nPos.push_back(x);
	nPos.push_back(y+1);
	return nPos;
}

vector <int> goSouth(vector<int> cPos) {
	int x = cPos[0];
	int y = cPos[1];
	vector <int> nPos;
	nPos.push_back(x+1);
	nPos.push_back(y);
	return nPos;
}

vector <int> goWest(vector<int> cPos) {
	int x = cPos[0];
	int y = cPos[1];
	vector <int> nPos;
	nPos.push_back(x);
	nPos.push_back(y-1);
	return nPos;
}

void displayMaze() {
	// This function displays the maze itself, with boundaries and numbering
	cout << "\n     ";
	for (int j=0; j<m; ++j)
		cout << j << " ";
	cout << "\n   ---";
	for (int j=0; j<m; ++j)
		cout << "--";
	for (int i=0; i<n; ++i) {
		cout << "\n " << i << " | ";
		for (int j=0; j<m; ++j)
			cout << maze[i][j] << " ";
		cout << "|";
	}
	cout << "\n   ---";
	for (int j=0; j<m; ++j)
		cout << "--";
	cout << endl;
}