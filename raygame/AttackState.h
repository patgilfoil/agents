#pragma once
#include "State.h"

class AttackState : public State {
public:
	AttackState(Agent* target, float speed) : m_target(target), m_speed(speed) {}
	virtual ~AttackState() {}

	virtual void init(Agent* agent) {}
	virtual void update(Agent* agent, float deltaTime);
	virtual void exit(Agent* agent) {}

private:
	float m_speed;
	Agent* m_target;
};