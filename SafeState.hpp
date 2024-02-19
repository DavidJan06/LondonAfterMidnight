#pragma once

#include <sstream>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Button.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class SafeState : public State
    {
    public:
        SafeState(GameDataRef data);

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

        sf::Vector2f _lockCenter;

        int _lock_0_rot;
        int _lock_1_rot;
        int _lock_2_rot;
        int _lock_3_rot;
        int dir_0;
        int dir_1;
        int dir_2;
        int dir_3;

        sf::Sprite _lock_0;
        sf::Sprite _lock_1;
        sf::Sprite _lock_2;
        sf::Sprite _lock_3;

        sf::Sprite _lockButton;

        sf::Sprite _lockPlate;

        sf::Text _dialogueText;
        sf::Clock _clock;

        Button _backButton;

    };
}
