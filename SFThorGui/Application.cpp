#include "Application.hpp"

Application::Application():
    m_window(sf::VideoMode(800, 600), "Application")
{
    if (m_icon.loadFromFile(""))
        m_window.setIcon(m_icon.getSize().x, m_icon.getSize().y, m_icon.getPixelsPtr());

    m_window.setFramerateLimit(60);

    m_actions[Action::Close] = thor::Action(sf::Event::Closed);
    m_system.connect(Action::Close, std::bind(&sf::Window::close, &m_window));
}

void Application::run()
{
    sf::Clock clock;

    while (m_window.isOpen()){

        m_actions.clearEvents();

        sf::Event event;
        while (m_window.pollEvent(event)){
            m_actions.pushEvent(event);
            m_desktop.HandleEvent(event);
        }

        m_actions.invokeCallbacks(m_system, &m_window);
        m_desktop.Update(clock.restart().asSeconds());

        m_sfgui.Display(m_window);
        m_window.display();
    }
}