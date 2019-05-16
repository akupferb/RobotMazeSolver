/**
 * @class Targets
 * @file targets.h
 * @author Ari Kupferberg, Bharat Mathur, Brenda Scheufele, Jagadesh Nagireddi, Raja Iskala
 * @date 20/05/19
 * @brief This header file defines the Targets class and its associated functions
 */
#pragma once
#include "Maze/Maze.h"
#include <iostream>
#include <vector>
#include <string>

class Targets {
private:
	std::vector<int> position;
	friend class Maze;

public:
	Targets();
	/**
	* @brief A contructor with input for the target position
	* @param pos A vector of the assigned position
	*/
	Targets(std::vector<int>);
	
	/**
	* @return Vector of target position
	*/
	std::vector<int> getTargetLoc();
	
	/**
	* @param pos Position to set for target
	*/
	void setTargetLoc(std::vector<int> pos) { position = pos; }
};
