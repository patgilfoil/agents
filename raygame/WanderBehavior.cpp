#include "WanderBehavior.h"

Vector2 WanderBehavior::update(Agent* agent, float deltaTime)
{
	float randRange = ((float)RAND_MAX) / 2;
	Vector2 targetPos = Vector2{ (float)rand() - randRange, (float)rand() - randRange}.normalize() * m_radius;
	targetPos += Vector2{ (float)rand() - randRange, (float)rand() - randRange }.normalize() * m_jitter;
	targetPos = targetPos.normalize() * m_radius;
	Vector2 heading = agent->getVelocity().normalize();
	targetPos += heading;

	m_prevTarget.x = targetPos.x;
	m_prevTarget.y = targetPos.y;

	Vector2 pos = agent->getPosition();

	Vector2 direction = targetPos - pos;
	direction = direction.normalize();
	direction = direction * 200;
	Vector2 force = direction - agent->getVelocity();
	return force;
}
