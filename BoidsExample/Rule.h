#pragma once

#include <memory>
#include <vector>

#include "SFML/System.hpp"

class Boid;

class Rule
{
public:
	virtual sf::Vector2f applyRule(std::shared_ptr<Boid> boid, std::vector<std::shared_ptr<Boid>>& m_boids) = 0;
	void setMultFactor(float factor) { m_multFactor = factor; };
	void setPerception(float factor) { m_perception = factor; };
protected:
	float m_multFactor = 1;
	float m_perception = 100;
};

