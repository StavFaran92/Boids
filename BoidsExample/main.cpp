#include <SFML/Graphics.hpp>
#include "Boid.h"
#include "Flock.h"
#include "CohesionRule.h"
#include "SeperationRule.h"
#include "AlignmentRule.h"
#include <memory>
#include "BoidsFactory.h"

#include "Application.h"

#include "CohesionController.h"
#include "SeperationController.h"
#include "AlignmentController.h"
#include <TGUI/TGUI.hpp>

int main()
{
    Application::get().init();

    auto& window = Application::get().getWindow();
    auto& gui = Application::get().getGUI();

    auto flock = std::make_shared<Flock>();

    tgui::VerticalLayout::Ptr layout = tgui::VerticalLayout::create();
    layout->setSize(300, 400);
    layout->setPosition(10, 10);
    gui.add(layout);

    auto cohesionRule = std::make_shared<CohesionRule>();
    flock->addRule(cohesionRule);
    CohesionController cohesionController("Cohesion", cohesionRule, layout);

    auto seperationRule = std::make_shared<SeperationRule>();
    flock->addRule(seperationRule);
    SeperationController seperationController("Seperation", seperationRule, layout);

    auto alignmentRule = std::make_shared<AlignmentRule>();
    flock->addRule(alignmentRule);
    AlignmentController alignmentController("Alignment", alignmentRule, layout);

    auto boids = BoidsFactory::generateBoids(100);

    for (const auto& boid : boids)
    {
        boid->joinFlock(flock);
    }

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float dt = deltaClock.restart().asSeconds();

        window.clear();

        for (auto& boid : boids)
        {
            boid->update(dt);
            boid->draw(window);
        }

        gui.draw();

        window.display();
    }

    return 0;
}
