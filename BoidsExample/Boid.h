#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include <memory>

class Flock;

class Boid : public std::enable_shared_from_this<Boid>
{
public:
	Boid();
	Boid(sf::Vector2f position, sf::Vector2f velocity, float size,const sf::Color& color);
	~Boid();

	void joinFlock(std::shared_ptr<Flock> flock);
	void leaveFlock();

	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	float getMaxSpeed() const;
	float getForce() const;

	void draw(sf::RenderWindow& window);
	void update(float deltaTime);


private:
	void init();
	void bound();
private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_size = 3;
	sf::Color m_color;
	float m_minSpeed = 10;
	float m_maxSpeed = 120;
	float m_force = .05f;


	std::shared_ptr<sf::CircleShape> m_shape = nullptr;
	std::shared_ptr<Flock> m_flock = nullptr;
};

