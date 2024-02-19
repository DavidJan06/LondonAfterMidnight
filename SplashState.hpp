#pragma once

#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class SplashState : public State
    {
    public:
        SplashState( Night_Rocket::GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        Night_Rocket::GameDataRef _data;

        sf::View _main;
        sf::RectangleShape _screen;

        sf::Clock _clock;

        sf::Sprite _logo;
        sf::Sprite _klara;
        sf::Sprite _david;

        sf::Text _title1;
        sf::Text _title2;
        sf::Text _title3;
        sf::Text _title4;

    };
}
