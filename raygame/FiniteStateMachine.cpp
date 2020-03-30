#include "FiniteStateMachine.h"
#include "State.h"
#include "Transition.h"

Vector2 FiniteStateMachine::update(Agent * agent, float deltaTime)
{
	if (m_currentState != nullptr) { 
		return Vector2{ 0.0f,0.0f };
	} 
	Transition* transition = m_currentState->getTriggeredTransition(agent);
	if (transition != nullptr) {
		m_currentState->exit(agent);
		m_currentState = transition->getTargetState();
		m_currentState->init(agent);
	}
	m_currentState->update(agent, deltaTime);
	return Vector2{ 0.0f,0.0f };
}
