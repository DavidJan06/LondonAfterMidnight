#pragma once

#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "AnimatedSprite.hpp"
#include "Button.hpp"
#include "Detective.hpp"
#include "Item.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::RectangleShape _screen;

        sf::View _view;

        Detective _detective;
        Item _safe;
        Item _armchair;
        Item _table;

        Item _calendar;
        Item _globe;
        Item _chandelier;

        sf::Sprite _roomInside;

        sf::Sprite _notebook;

        sf::FloatRect _doorShape;

        sf::Text _dialogueText;
        sf::Clock _clock;

        std::list<sf::FloatRect*> _collisionList;
        sf::RectangleShape _debugShape;
    };
}

