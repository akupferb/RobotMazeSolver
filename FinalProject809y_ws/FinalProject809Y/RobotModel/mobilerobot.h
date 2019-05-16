#pragma once
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotState/RobotState.h"
#include <stack>
#include <iostream>
#include <vector>
#include <string>

class MobileRobot {
private:
	std::string _name;
	std::vector<int> target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char start_marker;
	char visited_marker; // | or -
	char wrong_turn; // X or Y
	friend class Maze;
public:
	std::stack<char> state_stack;
	// Setters & Getters
	virtual void setTargetLoc(std::vector<int> pos) { target = pos; }
	virtual void setRobotLoc(std::vector<int> pos) { current_position = pos; }
	virtual std::string getName() const { return _name; }
	virtual std::vector<int> getStart() const { return start_position; }
	virtual std::vector<int> getRobotLoc() const { return current_position; }
	virtual std::vector<int> getTargetLoc() const { return target; }
	virtual char getStartMarker() const { return start_marker; }
	virtual char getVisitedMarker() const { return visited_marker; }
	virtual char getWrongTurnMarker() const { return wrong_turn; }
//	// Methods
	virtual std::vector<int> checkTarget(std::vector<int>) = 0;
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	
	virtual void update(std::string) = 0;
	void showStack(std::stack <char>);
	virtual ~MobileRobot(){};
};
