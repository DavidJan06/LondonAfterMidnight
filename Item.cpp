#include "Item.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    Item::Item(){}

    void Item::Init(GameDataRef Data, sf::String Texture, sf::String Name, sf::Vector2i ImgSize, sf::Vector2i Position, float Scale, int FrameNum, bool Loop, bool* collected, sf::Vector2i interactPos)
    {
        this->_data = Data;
        this->_name = Name;
        this->_pressed = false;
        this->_numCount = 0;
        this->_numMax = FrameNum;
        this->_imgSize = ImgSize;
        this->_loop = Loop;
        this->_interactable = true;
        this->_collected = collected;
        this->_interactPos = interactPos;

        this->_data->assets.LoadTexture(Name, Texture);
        this->_sprite.setTexture(this->_data->assets.GetTexture(Name));
        this->_sprite.setTextureRect(sf::IntRect(0, 0, this->_imgSize.x, this->_imgSize.y));
        this->_sprite.scale(Scale, Scale);
        this->_sprite.setPosition(sf::Vector2f(Position - sf::Vector2i(this->_sprite.getGlobalBounds().width/2, this->_sprite.getGlobalBounds().height/2)));

    }

    void Item::HandleInput(sf::Event event, sf::View view)
    {
        if(sf::Event::MouseButtonPressed == event.type)
        {
            if(event.mouseButton.button == sf::Mouse::Right)
            {
                this->_mousePos = sf::Mouse::getPosition();
                this->_mousePos = sf::Vector2i(this->_data->window.mapPixelToCoords(this->_mousePos, view));

                if((this->_mousePos.x > this->_sprite.getPosition().x) &&
                   (this->_mousePos.x < this->_sprite.getPosition().x + this->_sprite.getGlobalBounds().width) &&
                   (this->_mousePos.y > this->_sprite.getPosition().y) &&
                   (this->_mousePos.y < this->_sprite.getPosition().y+this->_sprite.getGlobalBounds().height))
                {
                    if(this->_interactable){
                        this->_data->_selectedItem = this;
                        //this->_data->_interact = true;
                    }
                }
            }
        }
    }

    void Item::Update( float dt )
    {
        if(this->_pressed and this->_interactable)
        {
            std::cout << this->_name << std::endl;

            this->_numCount++;
            
            if(this->_loop)
            {
                if(this->_numCount == this->_numMax)
                    this->_numCount = 0;
            }
            else
            {
                if(this->_numCount == this->_numMax-1){
                    this->_interactable = false;
                    *this->_collected = true;
                }
            }

            this->setPressed(false);
            this->_data->_selectedItem = nullptr;
            this->changed = true;
        }

        this->_sprite.setTextureRect(sf::IntRect(0, this->_numCount * this->_imgSize.y, this->_imgSize.x, this->_imgSize.y));
    }

    void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(this->_sprite, states);
    }

    void Item::setPressed(bool pressed)
    {
        _pressed = pressed;
    }

    bool Item::getPressed() const
    {
        return _pressed;
    }

    sf::Vector2f Item::getInteractPos() const
    {
        return sf::Vector2f(this->_interactPos);
    }

    sf::Vector2f Item::getPos() const
    {
        return sf::Vector2f(this->_sprite.getPosition());
    }

    sf::Vector2f Item::getSize() const
    {
        return sf::Vector2f(this->_sprite.getGlobalBounds().width, this->_sprite.getGlobalBounds().height);
    }

    void Item::setSpriteNum(int num)
    {
        this->_numCount = num;
    }

    int Item::getSpriteNum() const
    {
        return this->_numCount;
    }

    void Item::setCollisionShape(sf::Vector2f pos, sf::Vector2f size){
        this->_collisionShape =  sf::FloatRect(pos, size);
    }

    sf::FloatRect* Item::getCollisionShape()
    {
        return &this->_collisionShape;
    }
}
