#include "Application.hpp"

Application::Application()
{
    m_system.renderWindow.create(sf::VideoMode(800, 600), "Application");
    m_system.renderWindow.setFramerateLimit(60);

    m_system.actionMap[System::Action::Close] = thor::Action(sf::Event::Closed);
    m_system.callbackSystem.connect0(System::Action::Close, [this] {
        m_system.renderWindow.close();
    });
}

void Application::run()
{
    sf::Clock clock;

    while (m_system.renderWindow.isOpen()){

        m_system.actionMap.clearEvents();

        sf::Event event;
        while (m_system.renderWindow.pollEvent(event)){
            m_system.actionMap.pushEvent(event);
            m_system.desktop.HandleEvent(event);
        }
        
        auto frameTime = clock.restart();
        m_system.actionMap.invokeCallbacks(m_system.callbackSystem, &m_system.renderWindow);
        m_system.desktop.Update(frameTime.asSeconds());
        
        m_system.renderWindow.clear();
        m_system.sfgui.Display(m_system.renderWindow);
        m_system.renderWindow.display();
    }
}