#include "Maze/Maze.h"
#include "Target/Targets.h"
#include <iostream>
#include <vector>
#include <string>

Targets::Targets() {}

Targets::Targets(std::vector<int> vec) {
	position = vec;
}

std::vector<int> Targets::getTargetLoc() {
  return position;
}