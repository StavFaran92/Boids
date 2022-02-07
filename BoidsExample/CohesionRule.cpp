#include "CohesionRule.h"
#include "Math.h"

sf::Vector2f CohesionRule::applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids)
{
	if (m_boids.size() < 2)
		return sf::Vector2f();

	sf::Vector2f pc;

	int total = 0;
	for (const auto& pBoid : m_boids)
	{
		if (boid != pBoid)
		{
			float distance = getDistance(boid->getPosition(), pBoid->getPosition());
			if (distance < m_perception)
			{
				pc += pBoid->getPosition();
				total++;
			}
		}
	}

	if (total > 0)
	{
		pc /= (float)total;
		pc -= boid->getPosition();
		setMagnitude(pc, boid->getMaxSpeed());
		pc -= boid->getVelocity();
		limit(pc, boid->getForce());
	}

	pc *= m_multFactor;

	return pc;
}
