#include "SettingsState.hpp"
#include "PauseMenuState.hpp"

namespace Night_Rocket
{
    SettingsState::SettingsState(GameDataRef data) : _data(data){}

    void SettingsState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24,24,24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        // Data loading
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);
        this->_data->assets.LoadTexture("Switch", SWITCH);
        this->_data->assets.LoadTexture("SlideButton", SLIDEBUTTON);
        this->_data->assets.LoadTexture("Slidebar", SLIDEBAR);

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

        //Title
        this->_titleText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_titleText.setString("Options");
        this->_titleText.setCharacterSize(this->_screen.getSize().y / 10);
        this->_titleText.setFillColor(sf::Color::White);
        this->_titleText.setOrigin(this->_titleText.getGlobalBounds().width/2, this->_titleText.getGlobalBounds().height/2);
        this->_titleText.setPosition(this->_screen.getPosition().x, this->_screen.getSize().y / 10);

        //Toggle
        this->_toggleText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_toggleText.setString("Sound:");
        this->_toggleText.setCharacterSize(this->_screen.getSize().y / 15);
        this->_toggleText.setFillColor(sf::Color::White);
        this->_toggleText.setOrigin(this->_toggleText.getGlobalBounds().width/2, this->_toggleText.getGlobalBounds().height/2);
        this->_toggleText.setPosition(this->_screen.getPosition().x - this->_toggleText.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/6 - 20);

        this->_toggleMusic.setTexture(this->_data->assets.GetTexture("Switch"));
        this->_toggleMusic.setTextureRect(sf::IntRect(0, 0, 580, 220));
        this->_toggleMusic.setOrigin( this->_toggleMusic.getGlobalBounds().width/2, this->_toggleMusic.getGlobalBounds().height/2);
        this->_toggleMusic.scale(0.5, 0.5);
        this->_toggleMusic.setPosition(this->_screen.getPosition().x + this->_toggleMusic.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/6);

        //Slider
        this->_min = 585 - 27.5;
        this->_max = 1390 - 27.5;

        this->_sliderText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_sliderText.setString("Volume:");
        this->_sliderText.setCharacterSize(this->_screen.getSize().y / 15);
        this->_sliderText.setFillColor(sf::Color::White);
        this->_sliderText.setOrigin(this->_sliderText.getGlobalBounds().width/2, this->_sliderText.getGlobalBounds().height/2);
        this->_sliderText.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);

        this->_sliderBase.setTexture(this->_data->assets.GetTexture("Slidebar"));
        this->_sliderBase.setOrigin( this->_sliderBase.getGlobalBounds().width/2, this->_sliderBase.getGlobalBounds().height/2);
        this->_sliderBase.scale(0.5, 0.5);
        this->_sliderBase.rotate(90);
        this->_sliderBase.setPosition(this->_screen.getPosition().x - 27.5, this->_screen.getPosition().y +150);

        this->_sliderButton.setTexture(this->_data->assets.GetTexture("SlideButton"));
        this->_sliderButton.setOrigin( this->_sliderButton.getGlobalBounds().width/2, this->_sliderButton.getGlobalBounds().height/2);
        this->_sliderButton.scale(0.3, 0.3);
        float xPosition = (this->_data->_volume-0)/(100-0) * (this->_max-this->_min) + this->_min;
        this->_sliderButton.setPosition(xPosition, this->_screen.getPosition().y +150);

        //Buttons
        this->_backButton.SetUp("Back", this->_data->assets.GetFont("Nathan"), 70, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height*11/12));
        //this->_backButton.setDebug(true);

        std::cout << this->_screen.getPosition().x << std::endl;
    }

    void SettingsState::HandleInput()
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

                    sf::FloatRect temp1(this->_toggleMusic.getPosition().x - this->_toggleMusic.getGlobalBounds().width/2, this->_toggleMusic.getPosition().y - this->_toggleMusic.getGlobalBounds().height/2, this->_toggleMusic.getGlobalBounds().width, this->_toggleMusic.getGlobalBounds().height);
                    sf::FloatRect temp2(this->_sliderButton.getPosition().x - this->_sliderButton.getGlobalBounds().width/2, this->_sliderButton.getPosition().y - this->_sliderButton.getGlobalBounds().height/2, this->_sliderButton.getGlobalBounds().width, this->_sliderButton.getGlobalBounds().height);
                    sf::Vector2i _mousePos = sf::Mouse::getPosition();

                    if(temp1.contains(sf::Vector2f(_mousePos)))
                    {
                        this->_data->_soundOn = !this->_data->_soundOn;

                        if(this->_data->_soundOn){
                            this->_data->_sound.play();
                        }
                        else{
                            this->_data->_sound.pause();
                        }
                    }

                    if(temp2.contains(sf::Vector2f(_mousePos)))
                    {
                        this->_mouseDown = true;
                    }
                }
            }

            if(sf::Event::MouseButtonReleased == event.type)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    this->_mouseDown = false;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.RemoveState();
            }
        }
    }

    void SettingsState::Update(float dt)
    {
        //Switch
        if(this->_data->_soundOn){
            this->_toggleMusic.setTextureRect(sf::IntRect(580, 0, 580, 220));
        }
        else{
            this->_toggleMusic.setTextureRect(sf::IntRect(0, 0, 580, 220));
        }

        //Slider
        if(this->_mouseDown){
            sf::Vector2i _mousePos = sf::Mouse::getPosition();

            this->_sliderButton.setPosition(_mousePos.x, this->_sliderButton.getPosition().y);
            
            if(this->_sliderButton.getPosition().x < this->_min)
                this->_sliderButton.setPosition(this->_min, this->_sliderButton.getPosition().y);

            if(this->_sliderButton.getPosition().x > this->_max)
                this->_sliderButton.setPosition(this->_max, this->_sliderButton.getPosition().y);

            float volume = (this->_sliderButton.getPosition().x-this->_min)/(this->_max-this->_min) * (100-0) + 0;
            this->_data->_volume = volume;
            this->_data->_sound.setVolume(volume);

        }

        this->_backButton.update(sf::seconds(dt));
    }

    void SettingsState::Draw(float dt)
    {
        //this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_titleText);

        this->_data->window.draw(this->_toggleText);
        this->_data->window.draw(this->_toggleMusic);

        this->_data->window.draw(this->_sliderText);
        this->_data->window.draw(this->_sliderBase);
        this->_data->window.draw(this->_sliderButton);

        this->_data->window.draw(this->_backButton);

        this->_data->window.display();
    }
}
