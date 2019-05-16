#ifndef TRACKEDROBOT_H
#define TRACKEDROBOT_H
#include "Maze/Maze.h"
#include "Target/Targets.h"
#include "RobotModel/MobileRobot.h"
#include <vector>

class TrackedRobot: public MobileRobot {
private:
	std::string _name;
	std::vector<int> target;
	std::vector<int> start_position;
	std::vector<int> current_position;
	char start_marker = 't';
	char visited_marker = '-';
	char wrong_turn = 'X';
public:
	TrackedRobot(); // No args constructor
	TrackedRobot(Maze*); // Constructor
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
	// Methods
	virtual void update(std::string);
	virtual std::vector<int> checkTarget(std::vector<int>);
	virtual std::vector<int> Up(int,int);
	virtual std::vector<int> Down(int,int);
	virtual std::vector<int> Right(int,int);
	virtual std::vector<int> Left(int,int);
	virtual ~TrackedRobot(){}; // ~Destructor
};

#endif // TRACKEDROBOT_H
