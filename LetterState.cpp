#include "LetterState.hpp"

namespace Night_Rocket
{
    LetterState::LetterState(GameDataRef data) : _data(data){}

    void LetterState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24, 24, 24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("Letter", LETTER);
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);

        //Corners
        this->_cornerTopLeft.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerTopLeft.setOrigin( this->_cornerTopLeft.getGlobalBounds().width/2, this->_cornerTopLeft.getGlobalBounds().height/2);
        this->_cornerTopLeft.setScale(this->_screen.getSize().y/this->_cornerTopLeft.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerTopLeft.getLocalBounds().height/4);
        this->_cornerTopLeft.scale(-1, 1);
        this->_cornerTopLeft.setPosition(this->_screen.getPosition().x - this->_screen.getSize().x/2 + this->_cornerTopLeft.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/2 + this->_cornerTopLeft.getGlobalBounds().height/2);

        this->_cornerTopRight.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerTopRight.setOrigin( this->_cornerTopRight.getGlobalBounds().width/2, this->_cornerTopRight.getGlobalBounds().height/2);
        this->_cornerTopRight.setScale(this->_screen.getSize().y/this->_cornerTopRight.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerTopRight.getLocalBounds().height/4);
        this->_cornerTopRight.scale(1, 1);
        this->_cornerTopRight.setPosition(this->_screen.getPosition().x + this->_screen.getSize().x/2 - this->_cornerTopRight.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/2 + this->_cornerTopRight.getGlobalBounds().height/2);

        this->_cornerBottomLeft.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerBottomLeft.setOrigin( this->_cornerBottomLeft.getGlobalBounds().width/2, this->_cornerBottomLeft.getGlobalBounds().height/2);
        this->_cornerBottomLeft.setScale(this->_screen.getSize().y/this->_cornerBottomLeft.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerBottomLeft.getLocalBounds().height/4);
        this->_cornerBottomLeft.scale(-1, -1);
        this->_cornerBottomLeft.setPosition(this->_screen.getPosition().x - this->_screen.getSize().x/2 + this->_cornerBottomLeft.getGlobalBounds().width/2, this->_screen.getPosition().y + this->_screen.getSize().y/2 - this->_cornerBottomLeft.getGlobalBounds().height/2);

        this->_cornerBottomRight.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerBottomRight.setOrigin( this->_cornerBottomRight.getGlobalBounds().width/2, this->_cornerBottomRight.getGlobalBounds().height/2);
        this->_cornerBottomRight.setScale(this->_screen.getSize().y/this->_cornerBottomRight.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerBottomRight.getLocalBounds().height/4);
        this->_cornerBottomRight.scale(1, -1);
        this->_cornerBottomRight.setPosition(this->_screen.getPosition().x + this->_screen.getSize().x/2 - this->_cornerBottomRight.getGlobalBounds().width/2, this->_screen.getPosition().y + this->_screen.getSize().y/2 - this->_cornerBottomRight.getGlobalBounds().height/2);

        //Items
        this->_item.setTexture(this->_data->assets.GetTexture("Letter"));
        this->_item.setTextureRect(sf::IntRect(0, 0, 1300, 830));
        this->_item.setOrigin( this->_item.getGlobalBounds().width/2, this->_item.getGlobalBounds().height/2);
        //this->_item.scale(0.8, 0.8);
        this->_item.setPosition(sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y));

        //Buttons
        this->_backButton.SetUp("Close", this->_data->assets.GetFont("Nathan"), 70, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getSize().y*11/12));
        //this->_backButton.setDebug(true);
    }

    void LetterState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if(sf::Event::MouseMoved == event.type)
            {
                if(this->_backButton.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_backButton.setHover(true);
                }
                else
                {
                    this->_backButton.setHover(false);
                }
            }

            if(sf::Event::MouseButtonPressed == event.type)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(this->_spriteNum >= 5)
                    if(this->_backButton.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_backButton.setHover(false);
                        this->_data->_letter = true;
                        this->_data->machine.RemoveState();
                    }

                    sf::FloatRect temp(this->_item.getPosition().x - this->_item.getGlobalBounds().width/2, this->_item.getPosition().y - this->_item.getGlobalBounds().height/2, this->_item.getGlobalBounds().width, this->_item.getGlobalBounds().height);
                    sf::Vector2i _mousePos = sf::Mouse::getPosition();

                    if(temp.contains(sf::Vector2f(_mousePos)))
                    {
                        if(this->_spriteNum < 5)
                            this->_spriteNum++;
                    }
                }

                if(event.mouseButton.button == sf::Mouse::Right){
                    sf::FloatRect temp(this->_item.getPosition().x - this->_item.getGlobalBounds().width/2, this->_item.getPosition().y - this->_item.getGlobalBounds().height/2, this->_item.getGlobalBounds().width, this->_item.getGlobalBounds().height);
                    sf::Vector2i _mousePos = sf::Mouse::getPosition();

                    if(temp.contains(sf::Vector2f(_mousePos)))
                    {
                        if(this->_spriteNum > 0)
                            this->_spriteNum--;
                    }
                }
            }

            /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.RemoveState();
            }*/
        }
    }

    void LetterState::Update(float dt)
    {
        this->_item.setTextureRect(sf::IntRect(1300 * this->_spriteNum, 0, 1300, 830));

        this->_backButton.update(sf::seconds(dt));
    }

    void LetterState::Draw(float dt)
    {
        //this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_item);

        if(this->_spriteNum >= 5)
            this->_data->window.draw(this->_backButton);

        this->_data->window.display();
    }
}
