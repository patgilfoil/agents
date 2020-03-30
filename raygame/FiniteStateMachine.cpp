#include "FiniteStateMachine.h"
#include "State.h"
#include "Transition.h"

void FiniteStateMachine::update(Agent * agent, float deltaTime)
{
	if (m_currentState == nullptr) { 
		return;
	} 
	Transition* transition = m_currentState->getTriggeredTransition(agent);
	if (transition != nullptr) {
		m_currentState->exit(agent);
		m_currentState = transition->getTargetState();
		m_currentState->init(agent);
	}
	m_currentState->update(agent, deltaTime);
}
