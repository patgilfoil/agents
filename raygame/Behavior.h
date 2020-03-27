#pragma once
#include "Agent.h"	

enum eBehaviorResult { FAILURE, SUCCESS };

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	virtual Vector2 update(Agent* agent, float deltaTime) = 0;
};