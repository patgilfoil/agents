#pragma once
#include "Condition.h"

class WithinRangeCondition : public Condition
{
public:
	WithinRangeCondition(Agent* agent, float range) 
		: m_target(agent), m_range(range) {}
	virtual ~WithinRangeCondition() {}
	virtual bool test(Agent* agent) const;
private:
	Agent* m_target;
	float m_range;
};

