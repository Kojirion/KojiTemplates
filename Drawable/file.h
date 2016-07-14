#pragma once
#include <SFML/Graphics/Drawable.hpp>

class %{CN} : public sf::Drawable
{
public:
    
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};