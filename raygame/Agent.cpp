#include "Agent.h"
#include "Behavior.h"

void Agent::update(float deltaTime)
{
	//For each Behaviour in Behavior list
	for (auto i = m_BehaviorList.begin(); i != m_BehaviorList.end(); i++) {
		//Call the Behavior's update function
		(*i)->update(this, deltaTime);
	}
	//Add velocity times delta time to position
	if (m_Velocity.magnitude() > m_maxSpeed) {
		m_Velocity = m_Velocity.normalize() * m_maxSpeed;
	}
	m_Position += m_Velocity * GetFrameTime();
}

void Agent::draw()
{
	DrawRectangle((int)m_Position.x, (int)m_Position.y, 10, 10, m_color);
}

void Agent::addBehavior(Behavior * behavior)
{
	m_BehaviorList.insert(m_BehaviorList.end(), behavior);
}

void Agent::addForce(Vector2 force) {
	m_Velocity += force;
}