#pragma once
#include "Behavior.h"
class FleeBehavior : public Behavior
{
public:
	FleeBehavior() {}
	virtual ~FleeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
	void setTarget(Agent* target) { m_target = target; }

private:
	Agent* m_target;
};

