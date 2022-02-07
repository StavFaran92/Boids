#include "BoidsFactory.h"

#include "Math.h"

std::vector<std::shared_ptr<Boid>> BoidsFactory::generateBoids(int count)
{
    std::vector<std::shared_ptr<Boid>> boids;

    for (int i = 0; i < count; i++)
    {
        float angle = getRandom(0.f, 2.f * PI);
        float mag = getRandom(60.f, 120.f);

        float velH = cos(angle) * mag;
        float velV = sin(angle) * mag;

        int posX = getRandom(0, 800);
        int posY = getRandom(0, 600);
        boids.push_back(std::make_shared<Boid>(sf::Vector2f(posX, posY), sf::Vector2f(velH, velV), 10, sf::Color::Green));
    }

    return boids;
}
