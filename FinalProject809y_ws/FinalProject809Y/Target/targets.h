
#pragma once
#include "Maze/Maze.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Targets {
private:
	std::vector<int> position;
	friend class Maze;
	friend class MobileRobot;
	friend class TrackedRobot;
	friend class WheeledRobot;

public:
	Targets();
	Targets(std::vector<int>);
	std::vector<int> getTargetLoc();
	void setTargetLoc(std::vector<int> pos) { position = pos; }
};
