#include "KeyboardBehavior.h"

Vector2 KeyboardBehavior::update(Agent * agent, float deltaTime)
{
	Vector2 direction = { 0,0 };

	if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) direction.y = -1;
	if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) direction.y = 1;
	if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) direction.x = 1;
	if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) direction.x = -1;
	direction = direction.normalize();

	Vector2 force = direction * agent->getSpeed();

	force = force - agent->getVelocity();

	return force;
}
