#include "State.h"

Transition* State::getTriggeredTransition(GameObject* gameObject) { 
	for (auto transition : m_transitions) { 
		if (transition->hasTriggered(gameObject)) return transition; 
	} 
	return nullptr; 
}
