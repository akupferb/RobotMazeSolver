#ifndef DOWNSTATE_H
#define DOWNSTATE_H
#include "RobotState.h"
#include <string>
class DownState: public RobotState
{
public:
	virtual void update(std::stack<RobotState*>&, std::string) override;
	DownState();
	~DownState();

};

#endif // DOWNSTATE_H
