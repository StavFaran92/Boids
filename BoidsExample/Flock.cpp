#include "Flock.h"

#include "Boid.h"


Flock::Flock()
{
}

void Flock::addBoid(std::shared_ptr<Boid> boid)
{
	m_boids.push_back(boid);
}

void Flock::removeBoid(std::shared_ptr<Boid> boid)
{
	for (int i = 0; i < m_boids.size(); i++)
	{
		if (m_boids[i] == boid)
		{
			m_boids.erase(m_boids.begin() + i);
			break;
		}
	}
}

void Flock::addRule(std::shared_ptr<Rule> rule)
{
	m_rules.push_back(rule);
}

void Flock::removeRule(std::shared_ptr<Rule> rule)
{
	for (int i = 0; i < m_rules.size(); i++)
	{
		if (m_rules[i] == rule)
		{
			m_rules.erase(m_rules.begin() + i);
			break;
		}
	}
}

sf::Vector2f Flock::calculateVelocity(std::shared_ptr<Boid> boid)
{
	sf::Vector2f velocity;
	for (int i = 0; i < m_rules.size(); i++)
	{
		velocity += m_rules[i]->applyRule(boid, m_boids);
	}

	return velocity;
}
