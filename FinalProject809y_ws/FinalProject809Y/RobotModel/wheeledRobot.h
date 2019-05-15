#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <vector>

class WheeledRobot: public MobileRobot {
private:
	std::string _name;
	std::vector<int> target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char start_marker = 'w';
	char visited_marker = '|';
	char wrong_turn = 'Y';
public:
	WheeledRobot(Maze*):MobileRobot(){}; // Constructor
	// Setters & Getters
	virtual void setTargetLoc(std::vector<int> pos) { target = pos; }
	virtual void setRobotLoc(std::vector<int> pos) { current_position = pos; }
	virtual std::string getName();
	virtual std::vector<int> getStart();
	virtual std::vector<int> getRobotLoc();
	virtual std::vector<int> getTargetLoc();
	virtual char getStartMarker();
	virtual char getVisitedMarker();
	virtual char getWrongTurnMarker();
	// Methods
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
//	std::vector<int> numericInputs(Maze*);
	virtual ~WheeledRobot(){}; // ~Destructor
};

#endif // WHEELEDROBOT_H
