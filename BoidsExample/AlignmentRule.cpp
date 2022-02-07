#include "AlignmentRule.h"

#include "Math.h"
#include "Boid.h"

sf::Vector2f AlignmentRule::applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids)
{
	if (m_boids.size() < 2)
		return sf::Vector2f();

	sf::Vector2f pv;

	int total = 0;
	for (const auto& pBoid : m_boids)
	{
		if (boid != pBoid)
		{
			float distance = getDistance(boid->getPosition(), pBoid->getPosition());
			if (distance < m_perception)
			{
				pv += pBoid->getVelocity();
				total++;
			}
		}
	}

	if (total > 0)
	{
		pv /= (float)total;

		setMagnitude(pv, boid->getMaxSpeed());
		pv -= boid->getVelocity();
		limit(pv, boid->getForce());
	}

	pv *= m_multFactor;
	

	return pv;
}
