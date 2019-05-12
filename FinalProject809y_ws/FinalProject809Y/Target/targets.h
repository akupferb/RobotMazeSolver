#ifndef TARGETS_HPP_
#define TARGETS_HPP_
#include "Maze/Maze.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Targets {
private:
	std::vector<int> position;
	friend class Maze;
	friend class MobileRobot;
public:
	Targets(std::vector<int>);
};

#endif // __TARGETS_H__
