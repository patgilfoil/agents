#pragma once
#include "raylib.h"
#include <vector>

class Behavior;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}

	virtual void update(float deltaTime);

	virtual void draw();

	void addBehavior(Behavior* behavior);
	void addForce(Vector2 force);

	Vector2 getPosition() { return m_Position; }
	void setPosition(Vector2 position) { m_Position = position; }

	Vector2 getVelocity() { return m_Velocity; }
	void setVelocity(Vector2 velocity) { m_Velocity = velocity; }

protected:
	std::vector<Behavior*> m_BehaviorList;

	float m_maxSpeed = 200.0f;
	Vector2 m_Position;
	Vector2 m_Velocity;
};

