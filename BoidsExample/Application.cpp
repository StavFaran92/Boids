#include "Application.h"

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

Application Application::instance;

Application& Application::get()
{
    return instance;
}

void Application::init()
{
    m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(m_windowWidth, m_windowHeight), "Boids Demo");

     m_gui = std::make_shared< tgui::GuiSFML>( *m_window);
}

sf::RenderWindow& Application::getWindow()
{
    return *m_window;
}

int Application::getWindowWidth()
{
    return m_windowWidth;
}

int Application::getWindowHeight()
{
    return m_windowHeight;
}

tgui::GuiSFML& Application::getGUI()
{
    return *m_gui;
}

Application::Application()
{
    init();
}
