#include <Thor/Input.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

    enum class Action{
        Close
    };

int main()
{
    thor::ActionMap<Action> actionMap;
    thor::ActionMap<Action>::CallbackSystem system;

    actionMap[Action::Close] = thor::Action(sf::Event::Closed);

    sf::RenderWindow window(sf::VideoMode(800,600),"SFML with Thor");
    window.setFramerateLimit(60);

    system.connect(Action::Close, std::bind(&sf::RenderWindow::close, &window));

    while (window.isOpen()){
        actionMap.update(window);
        actionMap.invokeCallbacks(system, &window);
        
        window.clear();
        window.display();
    }
}