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
    class MainMenuState : public State
    {
    public:
        MainMenuState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::RectangleShape _screen;

        //Dinamic
        Button _play;
        Button _options;
        Button _exit;

        sf::Sprite _oneButton;
        sf::Sprite _twoButton;
        sf::Sprite _threeButton;

        //Static
        sf::Text _titleText;
        sf::Sprite _title;
        sf::Sprite _cornerTopLeft;
        sf::Sprite _cornerTopRight;
        sf::Sprite _cornerBottomLeft;
        sf::Sprite _cornerBottomRight;

    };
}
