#pragma once
#include "Behavior.h"
#include "Agent.h"

class Condition : public Behavior
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(Agent* agent) const = 0;

	virtual Vector2 execute(Agent* agent, float deltaTime) {
		return Vector2{ 0.0f,0.0f };
	}
};

class WithinRangeCondition : public Condition 
{
public:
	WithinRangeCondition(const Agent* target, float range) : m_target(target), m_range(range) {} 
	virtual ~WithinRangeCondition() {} 
	virtual bool test(Agent* gameObject) const; 
private: 
	const Agent* m_target; 
	float m_range;
};

