#include "SeekBehavior.h"

Vector2 SeekBehavior::update(Agent* agent, float deltaTime)
{
	//If the target is null
	if (agent == nullptr) {
		//Return a zero vector
		return Vector2({ 0.0f,0.0f });
	}
	//Get the Agent's position
	Vector2 agentPos = agent->getPosition();
	//Get the position of the target
	Vector2 targetPos = m_target->getPosition();

	//Calculate the vector describing the direction to the target and normalize it
	Vector2 direction = targetPos - agentPos;
	direction = direction.normalize();
	//Multiply the direction by the speed we want to move
	direction = direction * 250;
	//Subtract the Agent's current velocity from the result to get the force we need to apply
	Vector2 force = direction - agent->getVelocity();
	
	return force;
}
