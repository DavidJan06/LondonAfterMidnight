#include "ItemState.hpp"

namespace Night_Rocket
{
    ItemState::ItemState(GameDataRef data) : _data(data){}

    void ItemState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24, 24, 24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("Items", ITEMS);
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
        this->_item.setTexture(this->_data->assets.GetTexture("Items"));
        this->_item.setTextureRect(sf::IntRect(0, 0, 600, 600));
        this->_item.setOrigin( this->_item.getGlobalBounds().width/2, this->_item.getGlobalBounds().height/2);
        //this->_item.scale(0.5, 0.5);
        this->_item.setPosition(sf::Vector2f(this->_screen.getPosition().x, this->_screen.getSize().y * 4/12));

        //Text
        this->_text.setFont(this->_data->assets.GetFont("Nathan"));
        this->_text.setString("London After Midnight");
        this->_text.setCharacterSize(42);
        this->_text.setFillColor(sf::Color::White);
        this->_text.setOutlineColor(sf::Color::Black);
        this->_text.setOutlineThickness(1);
        this->_text.setOrigin(this->_text.getGlobalBounds().width/2, this->_text.getGlobalBounds().height/2);
        this->_text.setPosition(this->_screen.getPosition().x, this->_screen.getSize().y * 8/12);

        //Buttons
        this->_backButton.SetUp("Back", this->_data->assets.GetFont("Nathan"), 70, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height*11/12));
        //this->_backButton.setDebug(true);
    }

    void ItemState::HandleInput()
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
                    if(this->_backButton.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_backButton.setHover(false);
                        this->_data->machine.RemoveState();
                    }
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.RemoveState();
            }
        }
    }

    void ItemState::Update(float dt)
    {
        this->_item.setTextureRect(sf::IntRect(0, 600 * this->_data->_displayedItem, 600, 600));

        switch (this->_data->_displayedItem)
        {
        case 0:
            this->_text.setString("       Photo of late Madam Harriet Balfour.       \nI wonder why it was in a coat of Sir James Hamlin.");
            break;

        case 1:
            this->_text.setString("             A Colt revolver.             \nNot sure what model or year of production.\n  Pretty positive it is a murder weapon.  ");
            break;
        }

        this->_text.setOrigin(this->_text.getGlobalBounds().width/2, this->_text.getGlobalBounds().height/2);


        this->_backButton.update(sf::seconds(dt));
    }

    void ItemState::Draw(float dt)
    {
        //this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_item);

        this->_data->window.draw(this->_text);

        this->_data->window.draw(this->_backButton);

        this->_data->window.display();
    }
}
