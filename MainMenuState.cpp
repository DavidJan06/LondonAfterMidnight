#include "MainMenuState.hpp"
#include "SettingsState.hpp"
#include "GameState.hpp"

#include "EndState.hpp"

namespace Night_Rocket
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data){}

    void MainMenuState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24,24,24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("One", BUTTON_ONE);
        this->_data->assets.LoadTexture("Two", BUTTON_TWO);
        this->_data->assets.LoadTexture("Three", BUTTON_THREE);
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);
        this->_data->assets.LoadTexture("TwoShort", BUTTON_TWO_SHORT);
        this->_data->assets.LoadFont("Nathan", FONT_NATHAN);

        //Music
        this->_data->assets.LoadSoundBuffer("Menu", MENU);
        this->_data->_sound.setBuffer(this->_data->assets.GetSoundBuffer("Menu"));
        if(this->_data->_soundOn){
            this->_data->_sound.play();
        }
        this->_data->_sound.setLoop(true);
        this->_data->_sound.setVolume(this->_data->_volume);

        //Buttons
        this->_play.SetUp("Play", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f, 0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y - this->_screen.getSize().y/6));
        this->_options.SetUp("Options", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y));
        this->_exit.SetUp("Exit", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y/6));

        /*this->_play.setDebug(true);
        this->_options.setDebug(true);
        this->_exit.setDebug(true);*/

        //Title
        this->_titleText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_titleText.setString("London After Midnight");
        this->_titleText.setCharacterSize(this->_screen.getSize().y / 10); //85
        this->_titleText.setFillColor(sf::Color::White);
        this->_titleText.setOrigin(this->_titleText.getGlobalBounds().width/2, this->_titleText.getGlobalBounds().height/2);
        this->_titleText.setPosition(this->_screen.getPosition().x, this->_screen.getSize().y / 10);

        this->_title.setTexture(this->_data->assets.GetTexture("One"));
        this->_title.setOrigin(this->_title.getGlobalBounds().width/2, this->_title.getGlobalBounds().height/2);
        this->_title.setScale(this->_screen.getSize().y/this->_title.getLocalBounds().height/8, this->_screen.getSize().y/this->_title.getLocalBounds().height/8);
        this->_title.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y/2 - this->_title.getGlobalBounds().height/2);

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

    }

    void MainMenuState::HandleInput()
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
                if(this->_play.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_play.setHover(true);
                }
                else
                {
                    this->_play.setHover(false);
                }

                if(this->_options.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_options.setHover(true);
                }
                else
                {
                    this->_options.setHover(false);
                }

                if(this->_exit.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_exit.setHover(true);
                }
                else
                {
                    this->_exit.setHover(false);
                }
            }

            if(sf::Event::MouseButtonPressed == event.type)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(this->_play.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_data->_sound.stop();
                        this->_data->_sound.setLoop(false);
                        this->_play.setHover(false);
                        this->_data->machine.AddState(StateRef(new GameState(_data)), true);
                    }

                    if(this->_options.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_options.setHover(false);
                        this->_data->machine.AddState(StateRef(new SettingsState(_data)), false);
                    }

                    if(this->_exit.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_exit.setHover(false);
                        this->_data->window.close();
                    }
                }
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            this->_data->_sound.stop();

            //Switch to the Main Menu
            this->_data->machine.AddState(StateRef(new EndState(_data)), true);
        }
    }

    void MainMenuState::Update(float dt)
    {

        this->_play.update(sf::seconds(dt));
        this->_options.update(sf::seconds(dt));
        this->_exit.update(sf::seconds(dt));
    }

    void MainMenuState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_play);
        this->_data->window.draw(this->_options);
        this->_data->window.draw(this->_exit);

        this->_data->window.draw(this->_titleText);
        this->_data->window.draw(this->_title);

        this->_data->window.display();
    }
}
