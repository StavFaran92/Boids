#pragma once
#include <memory>

// Forward declerations
namespace sf {
    class RenderWindow;
}
namespace tgui {
    class GuiSFML;
}

class Application
{
public:
    static Application& get();
    ~Application() = default;

    void init();
    sf::RenderWindow& getWindow();
    int getWindowWidth();
    int getWindowHeight();
    tgui::GuiSFML& getGUI();
private:
    Application();
    static Application instance;

private:
    std::shared_ptr<sf::RenderWindow> m_window;
    std::shared_ptr<tgui::GuiSFML> m_gui;
    const int m_windowWidth = 1024;
    const int m_windowHeight = 768;
};

