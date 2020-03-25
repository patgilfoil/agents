#pragma once
#include "Behavior.h"
class WanderBehavior : public Behavior
{
public:
	WanderBehavior() {}
	virtual ~WanderBehavior() {}

	Vector2 update(Agent* agent, float deltaTime);

private:
	float m_radius = 1;
	float m_distance = 0;
	float m_jitter = 0;
	Vector2 m_prevTarget;
};

