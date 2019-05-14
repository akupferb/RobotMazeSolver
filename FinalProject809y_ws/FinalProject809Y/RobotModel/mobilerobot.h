#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <stack>

class MobileRobot {
private:
	friend class Maze;
public:
//	std::stack<robotstate::RobotState*> state_stack;
//	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
//	virtual void movedSpace(int,int)=0;
//	virtual void movedDown(int,int,Maze)=0;
//	virtual void movedRight(int,int,Maze)=0;
//	virtual void movedLeft(int,int,Maze)=0;
	// update stack method
//	virtual void update(std::string);
	virtual std::vector<int> getRobotLoc() = 0;
	virtual std::vector<int> getTargetLoc() = 0;
	virtual char getVisitedMarker() = 0;
	virtual char getWrongTurnMarker() = 0;
	virtual std::vector<int> getGoal() = 0;
};
