#pragma once

#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Button.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class ItemState : public State
    {
    public:
        ItemState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::RectangleShape _screen;

        sf::Sprite _cornerTopLeft;
        sf::Sprite _cornerTopRight;
        sf::Sprite _cornerBottomLeft;
        sf::Sprite _cornerBottomRight;

        sf::Sprite _item;

        sf::Text _text;

        Button _backButton;

    };
}