#pragma once

#include <memory>
#include <vector>
#include "SFML/System.hpp"

#include "CohesionRule.h"

class Boid;

class Flock
{
public:
	Flock();



	void addBoid(std::shared_ptr<Boid> boid);
	void removeBoid(std::shared_ptr<Boid> boid);

	void addRule(std::shared_ptr<Rule> rule);
	void removeRule(std::shared_ptr<Rule> rule);

	sf::Vector2f calculateVelocity(std::shared_ptr<Boid> boid);

private:
	std::vector<std::shared_ptr<Boid>> m_boids;
	std::vector<std::shared_ptr<Rule>> m_rules;

};

