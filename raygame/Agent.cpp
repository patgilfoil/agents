#include "Agent.h"

void Agent::update(float deltaTime)
{
	Vector2 force = {0,0};
	//For each Behaviour in Behavior list
	for (std::vector<Behavior*>::iterator iter = m_BehaviorList.begin(); iter != m_BehaviorList.end(); ++iter) {
		//Call the Behavior's update function
		//Add returned value to total force
		force += (*iter)->update(this, GetFrameTime());
	}
	//Add force multiplied by delta time to velocity
	m_Velocity = force * GetFrameTime();
	//Add velocity times delta time to position
	m_Position = m_Velocity * GetFrameTime();
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, RED);
}

void Agent::addBehavior(Behavior * behavior)
{
	m_BehaviorList.push_back(behavior);
}
