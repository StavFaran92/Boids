#pragma once

#include "Rule.h"
#include "Boid.h"

class CohesionRule : public Rule
{
public:
	// Inherited via Rule
	sf::Vector2f applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids) override;

private:
};

