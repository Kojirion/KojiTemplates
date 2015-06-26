#include <Thor/Input.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    thor::ActionMap<std::string> actionMap;
    thor::ActionMap<std::string>::CallbackSystem system;

    actionMap["close"] = thor::Action(sf::Event::Closed);

    sf::RenderWindow window(sf::VideoMode(800,600),"SFML with Thor");
    window.setFramerateLimit(60);

    system.connect("close", std::bind(&sf::RenderWindow::close, &window));

    while (window.isOpen()){
        actionMap.update(window);
        actionMap.invokeCallbacks(system, &window);
        
        window.clear();
        window.display();
    }
}