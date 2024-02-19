#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace Night_Rocket
{
    class Object : public sf::Drawable, public sf::Transformable
    {
        public:
            virtual void Update( float dt )=0;

        private:
            virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const = 0;

    };
}
