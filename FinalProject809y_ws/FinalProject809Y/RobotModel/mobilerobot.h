#pragma once
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include "RobotState/RobotState.h"
class MobileRobot {
private:
	std::string _name;
	Targets target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char visited_marker; // | or -
	char wrong_turn; // X or Y
	friend class Maze;
public:
	std::stack<robotstate::RobotState*> state_stack;
//	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	// update stack method
//	virtual void update(std::string);
	virtual void update(std::string);
	virtual void setTargetLoc(std::vector<int>) = 0;
	virtual void setRobotLoc(std::vector<int>) = 0;
	virtual std::string getName() = 0;
	virtual std::vector<int> getStart() = 0;
	virtual std::vector<int> getRobotLoc() = 0;
	virtual std::vector<int> getTargetLoc() = 0;
	virtual char getStartMarker() = 0;
	virtual char getVisitedMarker() = 0;
	virtual char getWrongTurnMarker() = 0;
};
