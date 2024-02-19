#pragma once

#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Button.hpp"
#include "Item.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class PauseMenuState : public State
    {
    public:
        PauseMenuState(GameDataRef data);

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

        sf::Sprite _note;

        sf::Sprite _foto;
        sf::Sprite _gun;

        //sf::RectangleShape _tempFoto;
        //sf::RectangleShape _tempGun;

        Button _resumeButton;
        Button _settingsButton;
        Button _exitButton;

    };
}
