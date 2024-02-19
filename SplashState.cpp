#include "SplashState.hpp"
#include "MainMenuState.hpp"

namespace Night_Rocket
{
    SplashState::SplashState(GameDataRef data) : _data(data), _main(sf::Vector2f(this->_data->window.getSize().x/2, this->_data->window.getSize().y/2), sf::Vector2f(this->_data->window.getSize().x, this->_data->window.getSize().y)){}

    void SplashState::Init()
    {
        this->_main.setViewport(sf::FloatRect(0, 0, 0.2f, 0.2f));

        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24,24,24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("Splash State Background" , SPLASH_SCREEN_LOGO);
        this->_data->assets.LoadTexture("Portreta" , SPLASH_SCREEN_PORTRET);
        this->_data->assets.LoadFont("Nathan", FONT_NATHAN);

        //Logo
        _logo.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        _logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, 0));
        _logo.scale(this->_screen.getSize().y/this->_logo.getGlobalBounds().height/1.2, this->_screen.getSize().y/this->_logo.getGlobalBounds().height/1.2);
        _logo.setOrigin(this->_logo.getLocalBounds().width/2, this->_logo.getLocalBounds().height/2);
        _logo.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);

        //Klara Portret
        _klara.setTexture(this->_data->assets.GetTexture("Portreta"));
        _klara.setTextureRect(sf::IntRect(0, 0, 1200, 1400));
        _klara.scale(this->_screen.getSize().y/this->_klara.getGlobalBounds().height/2, this->_screen.getSize().y/this->_klara.getGlobalBounds().height/2);
        _klara.setColor(sf::Color(_klara.getColor().r, _klara.getColor().g, _klara.getColor().b, 0));
        _klara.setOrigin(this->_klara.getLocalBounds().width/2, this->_klara.getLocalBounds().height/2);
        _klara.setPosition((this->_screen.getPosition().x - this->_screen.getSize().x/2 + this->_klara.getGlobalBounds().width/2), (this->_data->window.getSize().y/2));

        //David Portret
        _david.setTexture(this->_data->assets.GetTexture("Portreta"));
        _david.setTextureRect(sf::IntRect(1200, 0, 1200, 1400));
        _david.scale(this->_screen.getSize().y/this->_david.getGlobalBounds().height/2, this->_screen.getSize().y/this->_david.getGlobalBounds().height/2);
        _david.setColor(sf::Color(_david.getColor().r, _david.getColor().g, _david.getColor().b, 0));
        _david.setOrigin(this->_david.getLocalBounds().width/2, this->_david.getLocalBounds().height/2);
        _david.setPosition((this->_screen.getPosition().x + this->_screen.getSize().x/2 - this->_david.getGlobalBounds().width/2), (this->_data->window.getSize().y/2));

        //Starring
        this->_title1.setFont(this->_data->assets.GetFont("Nathan"));
        this->_title1.setString("Starring");
        this->_title1.setCharacterSize(this->_screen.getSize().y / 15); //85
        this->_title1.setFillColor(sf::Color::White);
        this->_title1.setOrigin(this->_title1.getLocalBounds().width/2, this->_title1.getLocalBounds().height/2);
        this->_title1.setPosition(this->_screen.getPosition().x, 20);
        this->_title1.setFillColor(sf::Color(_title1.getFillColor().r, _title1.getFillColor().g, _title1.getFillColor().b, 0));

        //Klara Jan
        this->_title2.setFont(this->_data->assets.GetFont("Nathan"));
        this->_title2.setString("Klara Jan");
        this->_title2.setCharacterSize(this->_screen.getSize().y / 20); //70
        this->_title2.setFillColor(sf::Color::White);
        this->_title2.setOrigin(this->_title2.getLocalBounds().width/2, this->_title2.getLocalBounds().height/2);
        this->_title2.setPosition(this->_screen.getPosition().x - 50, this->_screen.getPosition().y - this->_screen.getSize().y / 10);
        this->_title2.setFillColor(sf::Color(_title2.getFillColor().r, _title2.getFillColor().g, _title2.getFillColor().b, 0));

        //And
        this->_title3.setFont(this->_data->assets.GetFont("Nathan"));
        this->_title3.setString("And");
        this->_title3.setCharacterSize(this->_screen.getSize().y / 25); //50
        this->_title3.setFillColor(sf::Color::White);
        this->_title3.setOrigin(this->_title3.getLocalBounds().width/2, this->_title3.getLocalBounds().height/2);
        this->_title3.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y );
        this->_title3.setFillColor(sf::Color(_title3.getFillColor().r, _title3.getFillColor().g, _title3.getFillColor().b, 0));

        //David Jan
        this->_title4.setFont(this->_data->assets.GetFont("Nathan"));
        this->_title4.setString("David Jan");
        this->_title4.setCharacterSize(this->_screen.getSize().y / 20); //70
        this->_title4.setFillColor(sf::Color::White);
        this->_title4.setOrigin(this->_title4.getLocalBounds().width/2, this->_title4.getLocalBounds().height/2);
        this->_title4.setPosition(this->_screen.getPosition().x + 50, this->_screen.getPosition().y + this->_screen.getSize().y / 10);
        this->_title4.setFillColor(sf::Color(_title4.getFillColor().r, _title4.getFillColor().g, _title4.getFillColor().b, 0));

        //Music
        this->_data->assets.LoadSoundBuffer("Intro", INTRO);
        this->_data->_sound.setBuffer(this->_data->assets.GetSoundBuffer("Intro"));
        this->_data->_sound.play();
        //this->_sound.setVolume(25.f);
        //this->_sound.setPitch(1.2f);
    }

    void SplashState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            this->_data->_sound.stop();

            //Switch to the Main Menu
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::Update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > 10){
            if(this->_klara.getColor().a  > 0)
                this->_klara.setColor(sf::Color(_klara.getColor().r, _klara.getColor().g, _klara.getColor().b, _klara.getColor().a -5));

            if(this->_david.getColor().a  > 0)
                this->_david.setColor(sf::Color(_david.getColor().r, _david.getColor().g, _david.getColor().b, _david.getColor().a -5));

            if(this->_title1.getFillColor().a  > 0)
                this->_title1.setFillColor(sf::Color(_title1.getFillColor().r, _title1.getFillColor().g, _title1.getFillColor().b, _title1.getFillColor().a -5));

            if(this->_title2.getFillColor().a  > 0)
                this->_title2.setFillColor(sf::Color(_title2.getFillColor().r, _title2.getFillColor().g, _title2.getFillColor().b, _title2.getFillColor().a -5));

            if(this->_title3.getFillColor().a  > 0)
                this->_title3.setFillColor(sf::Color(_title3.getFillColor().r, _title3.getFillColor().g, _title3.getFillColor().b, _title3.getFillColor().a -5));

            if(this->_title4.getFillColor().a  > 0)
                this->_title4.setFillColor(sf::Color(_title4.getFillColor().r, _title4.getFillColor().g, _title4.getFillColor().b, _title4.getFillColor().a -5));
        }
        else if(this->_clock.getElapsedTime().asSeconds() > 6){
            if(this->_klara.getColor().a < 255)
                this->_klara.setColor(sf::Color(_klara.getColor().r, _klara.getColor().g, _klara.getColor().b, _klara.getColor().a +5));

            if(this->_david.getColor().a < 255)
                this->_david.setColor(sf::Color(_david.getColor().r, _david.getColor().g, _david.getColor().b, _david.getColor().a +5));

            if(this->_title1.getFillColor().a  < 255)
                this->_title1.setFillColor(sf::Color(_title1.getFillColor().r, _title1.getFillColor().g, _title1.getFillColor().b, _title1.getFillColor().a +5));

            if(this->_title2.getFillColor().a  < 255)
                this->_title2.setFillColor(sf::Color(_title2.getFillColor().r, _title2.getFillColor().g, _title2.getFillColor().b, _title2.getFillColor().a +5));

            if(this->_title3.getFillColor().a  < 255)
                this->_title3.setFillColor(sf::Color(_title3.getFillColor().r, _title3.getFillColor().g, _title3.getFillColor().b, _title3.getFillColor().a +5));

            if(this->_title4.getFillColor().a  < 255)
                this->_title4.setFillColor(sf::Color(_title4.getFillColor().r, _title4.getFillColor().g, _title4.getFillColor().b, _title4.getFillColor().a +5));
        }

        if(this->_clock.getElapsedTime().asSeconds() > 4){
            if(this->_logo.getColor().a  > 0)
                this->_logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, _logo.getColor().a -5));
        }
        else if(this->_clock.getElapsedTime().asSeconds() > 1){
            if(this->_logo.getColor().a < 255)
                this->_logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, _logo.getColor().a +5));
        }


        if(this->_clock.getElapsedTime().asSeconds() > 11)
        {
            this->_data->_sound.stop();
            //Switch to the Main Menu
            this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(_screen);
        //this->_data->window.setView(this->_main);
        this->_data->window.draw(this->_logo);
        this->_data->window.draw(this->_klara);
        this->_data->window.draw(this->_david);
        this->_data->window.draw(this->_title1);
        this->_data->window.draw(this->_title2);
        this->_data->window.draw(this->_title3);
        this->_data->window.draw(this->_title4);
        //this->_data->window.setView(this->_data->window.getDefaultView());

        this->_data->window.display();
    }
}
