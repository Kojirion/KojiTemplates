#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <Thor/Input/ActionMap.hpp>
#include <Thor/Input/EventSystem.hpp>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Desktop.hpp>

struct System{

    enum class Action{
        Close
    };

    using ActionMap = thor::ActionMap<Action>;

    sfg::SFGUI sfgui;
    sf::RenderWindow renderWindow;
    sfg::Desktop desktop;
    ActionMap actionMap;
    ActionMap::CallbackSystem callbackSystem;
};
