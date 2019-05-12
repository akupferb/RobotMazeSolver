#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <stack>

class MobileRobot {
private:
	char visited_marker; // | or -
	char wrong_turn; //X or Y
	Targets target;
	friend class Maze;
public:
	std::vector<int> current_position;
	MobileRobot();
	int x;
	int y;
	// methods
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
	virtual void movedUp(int,int,Maze);
	virtual void movedDown(int,int,Maze);
	virtual void movedRight(int,int,Maze);
	virtual void movedLeft(int,int,Maze);
	virtual void update(std::string);     //  =0 Doubt
	virtual std::vector<int> getRobotLoc();
	virtual ~MobileRobot(){};
};


#endif // MOBILEROBOT_H
