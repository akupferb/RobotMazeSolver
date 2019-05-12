#ifndef WHEELEDROBOT_H
#define WHEELEDROBOT_H

#include <vector>
#include "Maze/Maze.h"
#include "RobotModel/mobilerobot.h"

class WheeledRobot: public MobileRobot {
private:
	friend class Maze;
public:
	WheeledRobot(int, int, Targets);
	virtual std::vector<int> Up(int,int) override;
	virtual std::vector<int> Down(int,int) override;
	virtual std::vector<int> Right(int,int) override;
	virtual std::vector<int> Left(int,int) override;
	virtual void movedUp(int,int,Maze) override;
	virtual void movedDown(int,int,Maze) override;
	virtual void movedRight(int,int,Maze) override;
	virtual void movedLeft(int,int,Maze) override;
	virtual std::vector<int> getRobotLoc();
	virtual ~WheeledRobot(){};

};

#endif // WHEELEDROBOT_H
