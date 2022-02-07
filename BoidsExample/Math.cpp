#include "Math.h"

#include <random>

float getDistance(const sf::Vector2f a, const sf::Vector2f b)
{
	return getLength(a - b);
}

float getLength(const sf::Vector2f a)
{
	return std::sqrt(a.x * a.x + a.y * a.y);
}

float getRandom(float min, float max)
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1);
	return dis(e) * (max - min) + min;
}

int getRandom(int min, int max)
{
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

sf::Vector2f getNormal(const sf::Vector2f a)
{
	return a / getLength(a);
}

void setMagnitude(sf::Vector2f& v, float mag)
{
	v = getNormal(v) * mag;
}

void limit(sf::Vector2f& v, float limit)
{
	if (getLength(v) > limit)
		setMagnitude(v, limit);
}

float getAngle(const sf::Vector2f v)
{
	//return atan2((v.y), (v.x));
	return acos(getNormal(v).x) * 180 / PI;
}
