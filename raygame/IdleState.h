#pragma once
#include "State.h"

class IdleState : public State {
public:
	IdleState() {}
	virtual ~IdleState() {}

	virtual void init(Agent* agent) {}
	virtual void update(Agent* agent, float deltaTime) {}
	virtual void exit(Agent* agent) {}
};