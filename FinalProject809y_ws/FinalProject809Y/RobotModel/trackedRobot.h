#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H

#include <vector>
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"

class TrackedRobot: public MobileRobot {
private:
	std::vector<int> current_position;
	char visited_marker = '-'; // | or -
	char wrong_turn = 'X';     // X or Y
	std::vector<int> goal;
	friend class Maze;
public:
	TrackedRobot(int, int, std::vector<int>);
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
//	virtual void movedSpace(int,int);
//	virtual void movedDown(int,int,Maze*);
//	virtual void movedRight(int,int,Maze*);
//	virtual void movedLeft(int,int,Maze*);
	void setRobotLoc(std::vector<int> pos) { current_position = pos; }
	virtual std::vector<int> getRobotLoc();
	virtual char getVisitedMarker();
	virtual char getWrongTurnMarker();
	virtual std::vector<int> getGoal();
	virtual ~TrackedRobot(){};

};

#endif // TRACKEDROBOT_H
