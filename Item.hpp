#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Game.hpp"

namespace Night_Rocket
{
    class Item : public Object
    {
        public:
            Item();

            void Init(GameDataRef Data, sf::String Texture, sf::String Name, sf::Vector2i ImgSize, sf::Vector2i Position, float Scale, int FrameNum, bool Loop, bool* collected, sf::Vector2i _interactPos);
            void HandleInput(sf::Event event, sf::View view);
            void Update( float dt );

            void setPressed(bool pressed);
            bool getPressed() const;
            sf::Vector2f getInteractPos() const;

            sf::Vector2f getPos() const;
            sf::Vector2f getSize() const;

            void setSpriteNum(int num);
            int getSpriteNum() const;

            std::string _name;
            bool changed = false;

            void setCollisionShape(sf::Vector2f pos, sf::Vector2f size);
            sf::FloatRect* getCollisionShape();

        private:
            GameDataRef _data;

            sf::Vector2i _mousePos;
            sf::Sprite _sprite;
            bool _interactable;
            bool _pressed;
            int _numCount;
            int _numMax;
            sf::Vector2i _imgSize;
            bool _loop;
            bool* _collected;
            sf::Vector2i _interactPos;

            sf::FloatRect _collisionShape;

            virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
    };
}
