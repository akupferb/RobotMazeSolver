#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

Targets::Targets(std::vector<int> vec) {
	position = vec;
}