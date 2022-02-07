#include "SeperationRule.h"

#include "Boid.h"
#include "Math.h"

sf::Vector2f SeperationRule::applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids)
{
    if (m_boids.size() < 2)
        return sf::Vector2f();

    sf::Vector2f c;

    int total = 0;
    for (const auto& pBoid : m_boids)
    {
        if (boid != pBoid)
        {
            float distance = getDistance(boid->getPosition(), pBoid->getPosition());
            if (distance < m_perception)
            {
                sf::Vector2f diff = boid->getPosition() - pBoid->getPosition();
                diff /= distance;
                c += diff;
                total++;
            }
        }
    }

    if (total > 0)
    {
        c /= (float)total;
        setMagnitude(c, boid->getMaxSpeed());
        c -= boid->getVelocity();
        limit(c, boid->getForce());
    }

    c *= m_multFactor;

    return c;
}
