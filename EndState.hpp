#pragma once

#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class EndState : public State
    {
    public:
        EndState( Night_Rocket::GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        Night_Rocket::GameDataRef _data;

        sf::Sound _sound;

        sf::View _main;
        sf::RectangleShape _screen;

        sf::Clock _clock;


        sf::Text _theEnd;

        sf::Text _title;

        sf::Text _nameText1;
        sf::Text _andText;
        sf::Text _nameText2;

        sf::Sprite _scvLogo;
        sf::Sprite _vssLogo;

        sf::Sprite _logo;

        sf::Sprite _cornerTopLeft;
        sf::Sprite _cornerTopRight;
        sf::Sprite _cornerBottomLeft;
        sf::Sprite _cornerBottomRight;
    };
}
