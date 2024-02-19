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
    class SettingsState : public State
    {
    public:
        SettingsState(GameDataRef data);

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

        sf::Text _titleText;

        sf::Text _toggleText;
        sf::Sprite _toggleMusic;

        sf::Text _sliderText;
        sf::Sprite _sliderBase;
        sf::Sprite _sliderButton;
        int _min;
        int _max;

        bool _mouseDown = false;

        Button _backButton;
    };
}
