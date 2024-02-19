#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Animation.hpp"
#include "Game.hpp"

namespace Night_Rocket
{
    class AnimatedSprite : public sf::Drawable, sf::Transformable
    {
    public:
        AnimatedSprite();

        void Update(float dt);

        void setAnimation(const Animation& animation);
        void setFrameTime(float time);
        void play(const Animation& animation);
        const Animation* getAnimation() const;
        const std::size_t getCurrentFrame() const;
        float getFrameTime() const;
        void setFrame(std::size_t newFrame, bool resetTime = true);
        sf::FloatRect getLocalBounds() const;
        sf::FloatRect getGlobalBounds() const;


    private:
        Night_Rocket::GameDataRef _data;
        sf::Sprite _sprite;
        const Animation* _animation;
        float _frameTime = 0.2f;
        float _currentTime = 0;
        std::size_t _currentFrame;
        const sf::Texture* _texture;

        virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;

    };
}
