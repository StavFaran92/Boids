#pragma once

#include <vector>
#include "SFML/System.hpp"

#include "Boid.h"

class BoidsFactory
{
public:
	static std::vector<std::shared_ptr<Boid>> generateBoids(int count);
};

