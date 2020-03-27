#pragma once
#include "Behavior.h"
#include "GameObject.h"

class Condition : public Behavior
{
public:
	Condition() {}
	virtual ~Condition() {}

	virtual bool test(GameObject* gameObject) const = 0;

	virtual eBehaviorResult execute(GameObject* gameObject, float deltaTime) {
		if (test(gameObject))
			return eBehaviorResult::SUCCESS;
		return eBehaviorResult::FAILURE;
	}
};

class WithinRangeCondition : public Condition 
{
public:

};

