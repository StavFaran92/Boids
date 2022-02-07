#pragma once

#include "Rule.h"

class AlignmentRule : public Rule
{
	// Inherited via Rule
	sf::Vector2f applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids) override;
};

