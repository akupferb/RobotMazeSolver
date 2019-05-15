#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <vector>

class WheeledRobot: public MobileRobot {
private:
	Targets target;
	std::vector<int> current_position;
	char visited_marker = '|'; // | or -
	char wrong_turn = 'Y';     // X or Y
	std::vector<int> goal;
	friend class Maze;
public:
	WheeledRobot(std::vector<int>, std::vector<int>);
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
	void setRobotLoc(std::vector<int> pos) { current_position = pos; }
	virtual std::vector<int> getRobotLoc();
	virtual std::vector<int> getTargetLoc();
	virtual char getVisitedMarker();
	virtual char getWrongTurnMarker();
	virtual std::vector<int> getGoal();
	virtual ~WheeledRobot(){};

};

#endif // WHEELEDROBOT_H
