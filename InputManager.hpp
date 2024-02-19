#pragma once

#include <SFML/Graphics.hpp>

namespace Night_Rocket
{
    class InputManager
    {
    public:
        InputManager() {}
        ~InputManager() {}

        sf::Vector2i IsClicked(sf::Mouse::Button  button, sf::RenderWindow &window);

        sf::Vector2i GetMousePosition( sf::RenderWindow &window );

    private:
        bool _pressed = false;
        sf::Vector2i _position;

    };
}
