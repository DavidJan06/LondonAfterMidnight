#pragma once

#include <map>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Game.hpp"
#include "AnimatedSprite.hpp"
#include "Animation.hpp"
#include "Item.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    class Detective: public Object
    {
        public:
            Detective();

            void Init(GameDataRef Data, sf::Vector2i Position);
            void HandleInput(sf::Event event, sf::View View);
            void Update(float dt);

            AnimatedSprite _detective;

            sf::Vector2f getLocation();
            sf::Vector2f getMoveVector();
            void setLocation(sf::Vector2i pos);
            void setMovePos(sf::Vector2i movePos);

        private:
            GameDataRef _data;

            Animation Walk;
            Animation Interact;
            Animation Idle;

            sf::Vector2f _moveVector;
            sf::Vector2i _movePos;
            float _speed;
            bool _isRight;
            bool _interact;
            bool _move;
            std::map<int, float> _scaleMap;
            float _scale;

            virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
