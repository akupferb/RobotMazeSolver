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
	std::stack<robotstate::RobotState*> state_stack;
	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	virtual void movedup()=0;
	virtual void moveddown()=0;
	virtual void movedright()=0;
	virtual void movedleft()=0;
	// update stack method
	virtual void update(std::string);
	virtual std::vector<int> getRobotLoc();
	virtual ~MobileRobot(){};
};


#endif // MOBILEROBOT_H
