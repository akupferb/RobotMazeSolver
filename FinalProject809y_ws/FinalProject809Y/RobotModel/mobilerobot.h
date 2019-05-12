#ifndef MOBILEROBOT_H
#define MOBILEROBOT_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Target/Targets.h"
#include <stack>

class MobileRobot {
private:
	std::vector<int> current_position;
	char visited_marker; // | or -
	char wrong_turn; //X or Y
	Targets target;
	friend class Maze;
public:
	MobileRobot();
	int x;
	int y;
	// methods
	virtual std::vector<int> Up(int,int)=0;
	virtual std::vector<int> Down(int,int)=0;
	virtual std::vector<int> Right(int,int)=0;
	virtual std::vector<int> Left(int,int)=0;
	virtual void movedup()=0;
	virtual void moveddown()=0;
	virtual void movedright()=0;
	virtual void movedleft()=0;
	virtual void update(std::string);     //  =0 Doubt
	virtual std::vector<int> getRobotLoc();
	virtual ~MobileRobot(){};
};


#endif // MOBILEROBOT_H
