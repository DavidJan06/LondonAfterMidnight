#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace Night_Rocket
{
    class Button : public sf::Drawable, public sf::Transformable
    {
        public:
            explicit Button();

            void SetUp(sf::String text, const sf::Font& font, float fontSize, sf::Color color, const sf::Texture& texture, sf::Vector2f scale, sf::Vector2f position);

            sf::FloatRect getLocalBounds() const;
            sf::FloatRect getGlobalBounds() const;

            void setHover(bool hover);
            bool getHover() const;

            void setDebug(bool debug);
            bool getDebug() const;

            void setFlap(bool flap);
            bool getFlap() const;

            bool isInObject(sf::Vector2i position);

            void update(sf::Time deltaTime);

        private:
            sf::Text m_text;
            sf::Color m_color;

            sf::Sprite m_left;
            sf::Sprite m_right;

            bool m_flap = true;

            bool m_debug = false;
            sf::RectangleShape m_debugger;

            bool m_hover = false;

            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
