#include "WithinRangeCondition.h"

bool WithinRangeCondition::test(Agent * agent) const
{
	Vector2 targetPos = m_target->getPosition();

	Vector2 pos = agent->getPosition();

	float distance = (targetPos - pos).magnitude();

	return distance <= m_range;
}
