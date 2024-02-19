#include "AnimatedSprite.hpp"

namespace Night_Rocket
{
    AnimatedSprite::AnimatedSprite()
    {

    }

    void AnimatedSprite::Update(float dt)
    {
        // if we have a valid animation
        if (_animation)
        {
            // add delta time
            _currentTime += dt;

            // if current time is bigger then the frame time advance one frame
            if (_currentTime >= _frameTime)
            {
                // reset time, but keep the remainder
                _currentTime = _currentTime - _frameTime;

                // get next Frame index
                if (_currentFrame + 1 < _animation->getSize())
                    _currentFrame++;
                else
                {
                    _currentFrame = 0; // reset to start
                }
                // set the current frame, not reseting the time
                setFrame(_currentFrame, false);
            }
        }
    }

    void AnimatedSprite::setAnimation(const Animation& animation)
    {
        _animation = &animation;
        _texture = _animation->getSpriteSheet();
        _sprite.setTexture(*_texture);
        _currentFrame = 0;
        setFrame(_currentFrame);
    }

    void AnimatedSprite::setFrameTime(float time)
    {
        _frameTime = time;
    }

    void AnimatedSprite::play(const Animation& animation)
    {
        if (getAnimation() != &animation)
            setAnimation(animation);
    }

    const Animation* AnimatedSprite::getAnimation() const
    {
        return _animation;
    }

    const std::size_t AnimatedSprite::getCurrentFrame() const
    {
        return _currentFrame;
    }

    float AnimatedSprite::getFrameTime() const
    {
        return _frameTime;
    }

    void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime)
    {
        if (_animation)
        {
            this->_sprite.setTextureRect(_animation->getFrame(newFrame));
        }

        if (resetTime)
            _currentTime = 0;
    }

    sf::FloatRect AnimatedSprite::getLocalBounds() const
    {
        return this->_sprite.getLocalBounds();
    }

    sf::FloatRect AnimatedSprite::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
    }

    void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(this->_sprite, states);
    }
}
