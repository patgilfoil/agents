#pragma once
#include "Agent.h"
#include <vector>

class GameObject;
class Transition;

class State
{
public:
	State() {}
	~State() {}

	virtual void update(GameObject* agent) = 0;
	virtual void init(GameObject* agent) = 0;
	virtual void end(GameObject* agent) = 0;

	void addTransition(Transition* transition) {
		m_transitions.push_back(transition);
	}

	Transition* getTriggeredTransition(GameObject* gameObject);

protected:
	std::vector<Transition*> m_transitions;
};

