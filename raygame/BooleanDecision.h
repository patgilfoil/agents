#pragma once
#include "Decision.h"
#include "Condition.h"
class BooleanDecision : public Decision
{
public:
	BooleanDecision(Decision* a, Decision* b, Condition* cond) : m_a(a), m_b(b), m_condition(cond) {}

	virtual void makeDecision(Agent* agent, float deltaTime);
protected:
	virtual bool testCondition(Agent* agent) { return false; }
private:
	Decision* m_a;
	Decision* m_b;
	Condition* m_condition;
};

