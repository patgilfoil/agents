#include "Agent.h"

void Agent::update(float deltaTime)
{
	//Set force to 0
	//For each Behaviour in Behavior list
		//Call the Behavior's update function 
		//Add returned value to total force
	//Add force multiplied by delta time to velocity
	//Add velocity times delta time to position
}

void Agent::draw()
{
	DrawRectangle(m_Position.x, m_Position.y, 10, 10, RED);
}

void Agent::addBehavior(Behavior * behavior)
{
	m_BehaviorList.push_back(behavior);
}
