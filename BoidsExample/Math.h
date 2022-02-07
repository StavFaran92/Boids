#pragma once

#include "SFML/System.hpp"

static const float PI = 3.14159265359f;

float getDistance(const sf::Vector2f a, const sf::Vector2f b);

float getLength(const sf::Vector2f a);

float getRandom(float min, float max);
int getRandom(int min, int max);
sf::Vector2f getNormal(const sf::Vector2f a);
void setMagnitude(sf::Vector2f& v, float mag);
void limit(sf::Vector2f& v, float limit);
float getAngle(const sf::Vector2f v);