#include "Boid.h"

#include "Flock.h"
#include "Math.h"
#include "Application.h"

Boid::Boid()
	: m_position(0, 0), m_velocity(0,0), m_size(1), m_color(sf::Color::White)
{
	init();
}

Boid::Boid(sf::Vector2f position, sf::Vector2f velocity, float size, const sf::Color& color)
	: m_position(position), m_velocity(velocity), m_size(size), m_color(color)
{
	init();
}



Boid::~Boid()
{
}

void Boid::init()
{
	m_shape = std::make_shared<sf::CircleShape>(m_size, 3);
	m_shape->setFillColor(m_color);
	m_shape->setOrigin(m_size, m_size);
}

void Boid::joinFlock(std::shared_ptr<Flock> flock)
{
	flock->addBoid(shared_from_this());
	m_flock = flock;
}

void Boid::leaveFlock()
{
	m_flock->removeBoid(shared_from_this());
	m_flock = nullptr;
}

void Boid::draw(sf::RenderWindow& window)
{
	window.draw(*m_shape);
	

}

void Boid::update(float deltaTime)
{
	if (m_flock)
	{
		m_velocity += m_flock->calculateVelocity(shared_from_this());
	}

	m_position += m_velocity * deltaTime;

	bound();

	limit(m_velocity, m_maxSpeed);

	m_shape->setPosition(m_position);
	m_shape->setRotation(getAngle(m_velocity) + 90);
}

void Boid::bound()
{
	if (m_position.x < 0)
		m_position.x = Application::get().getWindowWidth();
	else if (m_position.x > Application::get().getWindowWidth())
		m_position.x = 0;

	if (m_position.y < 0)
		m_position.y = Application::get().getWindowHeight();
	else if (m_position.y > Application::get().getWindowHeight())
		m_position.y = 0;
}

sf::Vector2f Boid::getPosition() const 
{
	return m_position;
}

sf::Vector2f Boid::getVelocity() const
{
	return m_velocity;
}

float Boid::getMaxSpeed() const
{
	return m_maxSpeed;
}

float Boid::getForce() const
{
	return m_force;
}
