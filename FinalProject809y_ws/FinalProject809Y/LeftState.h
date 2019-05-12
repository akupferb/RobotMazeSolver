#ifndef LEFTSTATE_H
#define LEFTSTATE_H
#include "RobotState.h"
class LeftState: public RobotState
{
public:
	virtual void update(std::stack<RobotState*>&, std::string) override;
	LeftState();
	~LeftState();

};

#endif // LEFTSTATE_H
