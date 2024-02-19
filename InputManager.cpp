#include "InputManager.hpp"

namespace Night_Rocket
{
    sf::Vector2i InputManager::IsClicked(sf::Mouse::Button  button, sf::RenderWindow &window)
    {
        if(sf::Mouse::isButtonPressed(button))
        {
            if(!_pressed)
            {
                _position = sf::Mouse::getPosition(window);
                printf("true");
                _pressed = true;
            }
        }
        else
        {
            printf("true");
            _pressed = false;
        }

        return _position;
    }

    sf::Vector2i InputManager::GetMousePosition( sf::RenderWindow &window )
    {
        return sf::Mouse::getPosition(window);
    }
}
