#include "EndState.hpp"
#include "MainMenuState.hpp"

namespace Night_Rocket
{
    EndState::EndState(GameDataRef data) : _data(data){}

    void EndState::Init()
    {
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24,24,24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("Splash State Background" , SPLASH_SCREEN_LOGO);
        this->_data->assets.LoadTexture("VSS" , VSS);
        this->_data->assets.LoadTexture("SCV" , SCV);
        this->_data->assets.LoadFont("Nathan", FONT_NATHAN);
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);

        //The End
        this->_theEnd.setFont(this->_data->assets.GetFont("Nathan"));
        this->_theEnd.setString("The End");
        this->_theEnd.setCharacterSize(this->_screen.getSize().y / 8);
        this->_theEnd.setFillColor(sf::Color::White);
        this->_theEnd.setOrigin(this->_theEnd.getLocalBounds().width/2, this->_theEnd.getLocalBounds().height/2);
        this->_theEnd.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);
        this->_theEnd.setFillColor(sf::Color(_theEnd.getFillColor().r, _theEnd.getFillColor().g, _theEnd.getFillColor().b, 0));

        //Starring
        this->_title.setFont(this->_data->assets.GetFont("Nathan"));
        this->_title.setString("Programmer");
        this->_title.setCharacterSize(this->_screen.getSize().y / 15);
        this->_title.setFillColor(sf::Color::White);
        this->_title.setOrigin(this->_title.getLocalBounds().width/2, this->_title.getLocalBounds().height/2);
        this->_title.setPosition(this->_screen.getPosition().x, 20);
        this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, 0));

        //Name 1
        this->_nameText1.setFont(this->_data->assets.GetFont("Nathan"));
        this->_nameText1.setString("Klara Jan");
        this->_nameText1.setCharacterSize(this->_screen.getSize().y / 10);
        this->_nameText1.setFillColor(sf::Color::White);
        this->_nameText1.setOrigin(this->_nameText1.getLocalBounds().width/2, this->_nameText1.getLocalBounds().height/2);
        this->_nameText1.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y - this->_screen.getSize().y / 10);
        this->_nameText1.setFillColor(sf::Color(_nameText1.getFillColor().r, _nameText1.getFillColor().g, _nameText1.getFillColor().b, 0));

        //And
        this->_andText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_andText.setString("David Jan");
        this->_andText.setCharacterSize(this->_screen.getSize().y / 10);
        this->_andText.setFillColor(sf::Color::White);
        this->_andText.setOrigin(this->_andText.getLocalBounds().width/2, this->_andText.getLocalBounds().height/2);
        this->_andText.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y + 20);
        this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, 0));

        //Name 2
        this->_nameText2.setFont(this->_data->assets.GetFont("Nathan"));
        this->_nameText2.setString(L"Nina Ambrožič");
        this->_nameText2.setCharacterSize(this->_screen.getSize().y / 10);
        this->_nameText2.setFillColor(sf::Color::White);
        this->_nameText2.setOrigin(this->_nameText2.getLocalBounds().width/2, this->_nameText2.getLocalBounds().height/2);
        this->_nameText2.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y / 10);
        this->_nameText2.setFillColor(sf::Color(_nameText2.getFillColor().r, _nameText2.getFillColor().g, _nameText2.getFillColor().b, 0));

        //scvLogo
        _scvLogo.setTexture(this->_data->assets.GetTexture("SCV"));
        _scvLogo.setColor(sf::Color(_scvLogo.getColor().r, _scvLogo.getColor().g, _scvLogo.getColor().b, 0));
        _scvLogo.scale(0.3, 0.3);
        _scvLogo.setOrigin(this->_scvLogo.getLocalBounds().width/2, this->_scvLogo.getLocalBounds().height/2);
        _scvLogo.setPosition(this->_screen.getPosition().x - this->_screen.getSize().x/6, this->_screen.getPosition().y);

        //vssLogo
        _vssLogo.setTexture(this->_data->assets.GetTexture("VSS"));
        _vssLogo.setColor(sf::Color(_vssLogo.getColor().r, _vssLogo.getColor().g, _vssLogo.getColor().b, 0));
        _vssLogo.scale(1, 1);
        _vssLogo.setOrigin(this->_vssLogo.getLocalBounds().width/2, this->_vssLogo.getLocalBounds().height/2);
        _vssLogo.setPosition(this->_screen.getPosition().x + this->_screen.getSize().x/5, this->_screen.getPosition().y);

        //Logo
        _logo.setTexture(this->_data->assets.GetTexture("Splash State Background"));
        _logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, 0));
        _logo.scale(this->_screen.getSize().y/this->_logo.getGlobalBounds().height/1.2, this->_screen.getSize().y/this->_logo.getGlobalBounds().height/1.2);
        _logo.setOrigin(this->_logo.getLocalBounds().width/2, this->_logo.getLocalBounds().height/2);
        _logo.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);

         //Corners
        this->_cornerTopLeft.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, 0));
        this->_cornerTopLeft.setOrigin( this->_cornerTopLeft.getGlobalBounds().width/2, this->_cornerTopLeft.getGlobalBounds().height/2);
        this->_cornerTopLeft.setScale(this->_screen.getSize().y/this->_cornerTopLeft.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerTopLeft.getLocalBounds().height/4);
        this->_cornerTopLeft.scale(-1, 1);
        this->_cornerTopLeft.setPosition(this->_screen.getPosition().x - this->_screen.getSize().x/2 + this->_cornerTopLeft.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/2 + this->_cornerTopLeft.getGlobalBounds().height/2);

        this->_cornerTopRight.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, 0));
        this->_cornerTopRight.setOrigin( this->_cornerTopRight.getGlobalBounds().width/2, this->_cornerTopRight.getGlobalBounds().height/2);
        this->_cornerTopRight.setScale(this->_screen.getSize().y/this->_cornerTopRight.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerTopRight.getLocalBounds().height/4);
        this->_cornerTopRight.scale(1, 1);
        this->_cornerTopRight.setPosition(this->_screen.getPosition().x + this->_screen.getSize().x/2 - this->_cornerTopRight.getGlobalBounds().width/2, this->_screen.getPosition().y - this->_screen.getSize().y/2 + this->_cornerTopRight.getGlobalBounds().height/2);

        this->_cornerBottomLeft.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, 0));
        this->_cornerBottomLeft.setOrigin( this->_cornerBottomLeft.getGlobalBounds().width/2, this->_cornerBottomLeft.getGlobalBounds().height/2);
        this->_cornerBottomLeft.setScale(this->_screen.getSize().y/this->_cornerBottomLeft.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerBottomLeft.getLocalBounds().height/4);
        this->_cornerBottomLeft.scale(-1, -1);
        this->_cornerBottomLeft.setPosition(this->_screen.getPosition().x - this->_screen.getSize().x/2 + this->_cornerBottomLeft.getGlobalBounds().width/2, this->_screen.getPosition().y + this->_screen.getSize().y/2 - this->_cornerBottomLeft.getGlobalBounds().height/2);

        this->_cornerBottomRight.setTexture(this->_data->assets.GetTexture("Corner"));
        this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, 0));
        this->_cornerBottomRight.setOrigin( this->_cornerBottomRight.getGlobalBounds().width/2, this->_cornerBottomRight.getGlobalBounds().height/2);
        this->_cornerBottomRight.setScale(this->_screen.getSize().y/this->_cornerBottomRight.getLocalBounds().height/4, this->_screen.getSize().y/this->_cornerBottomRight.getLocalBounds().height/4);
        this->_cornerBottomRight.scale(1, -1);
        this->_cornerBottomRight.setPosition(this->_screen.getPosition().x + this->_screen.getSize().x/2 - this->_cornerBottomRight.getGlobalBounds().width/2, this->_screen.getPosition().y + this->_screen.getSize().y/2 - this->_cornerBottomRight.getGlobalBounds().height/2);

        //Music
        this->_data->assets.LoadSoundBuffer("Ending", ENDING);
        this->_data->_sound.setBuffer(this->_data->assets.GetSoundBuffer("Ending"));
        if(this->_data->_soundOn){
            this->_data->_sound.play();
        }
        this->_data->_sound.setVolume(this->_data->_volume);
    }

    void EndState::HandleInput()
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

    void EndState::Update(float dt)
    {
        switch((int)this->_clock.getElapsedTime().asSeconds()){
            // The End
            case 0 ... 1:
                if(this->_theEnd.getFillColor().a < 255)
                    this->_theEnd.setFillColor(sf::Color(_theEnd.getFillColor().r, _theEnd.getFillColor().g, _theEnd.getFillColor().b, _theEnd.getFillColor().a +5));
                
                if(this->_cornerTopLeft.getColor().a < 255)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a +5));

                if(this->_cornerTopRight.getColor().a < 255)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a +5));
                
                if(this->_cornerBottomLeft.getColor().a < 255)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a +5));
                
                if(this->_cornerBottomRight.getColor().a < 255)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a +5));
                break;
            case 3 ... 4:
                if(this->_theEnd.getFillColor().a > 0)
                    this->_theEnd.setFillColor(sf::Color(_theEnd.getFillColor().r, _theEnd.getFillColor().g, _theEnd.getFillColor().b, _theEnd.getFillColor().a -5));
                
                if(this->_cornerTopLeft.getColor().a > 0)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a -5));

                if(this->_cornerTopRight.getColor().a > 0)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a -5));
                
                if(this->_cornerBottomLeft.getColor().a > 0)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a -5));
                
                if(this->_cornerBottomRight.getColor().a > 0)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a -5));
                break;

            // Developer
            case 5 ... 6:
                if(this->_title.getFillColor().a < 255)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a +5));
            
                if(this->_andText.getFillColor().a < 255)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a +5));
                
                if(this->_cornerTopLeft.getColor().a < 255)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a +5));

                if(this->_cornerTopRight.getColor().a < 255)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a +5));
                
                if(this->_cornerBottomLeft.getColor().a < 255)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a +5));
                
                if(this->_cornerBottomRight.getColor().a < 255)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a +5));
                
                break;
            case 8 ... 9:
                if(this->_title.getFillColor().a > 0)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a -5));

                if(this->_andText.getFillColor().a > 0)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a -5));
                
                if(this->_cornerTopLeft.getColor().a > 0)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a -5));

                if(this->_cornerTopRight.getColor().a > 0)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a -5));
                
                if(this->_cornerBottomLeft.getColor().a > 0)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a -5));
                
                if(this->_cornerBottomRight.getColor().a > 0)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a -5));
                
                break;
            
            // Art
            case 10 ... 11:
                // set up
                this->_title.setString("Illustrators");
                this->_title.setOrigin(this->_title.getLocalBounds().width/2, this->_title.getLocalBounds().height/2);

                this->_andText.setString("And");
                this->_andText.setCharacterSize(this->_screen.getSize().y / 25);
                this->_andText.setOrigin(this->_andText.getLocalBounds().width/2, this->_andText.getLocalBounds().height/2);
                // set up

                if(this->_title.getFillColor().a < 255)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a +5));
                
                if(this->_nameText1.getFillColor().a < 255)
                    this->_nameText1.setFillColor(sf::Color(_nameText1.getFillColor().r, _nameText1.getFillColor().g, _nameText1.getFillColor().b, _nameText1.getFillColor().a +5));

                if(this->_andText.getFillColor().a < 255)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a +5));

                if(this->_nameText2.getFillColor().a < 255)
                    this->_nameText2.setFillColor(sf::Color(_nameText2.getFillColor().r, _nameText2.getFillColor().g, _nameText2.getFillColor().b, _nameText2.getFillColor().a +5));
                
                if(this->_cornerTopLeft.getColor().a < 255)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a +5));

                if(this->_cornerTopRight.getColor().a < 255)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a +5));
                
                if(this->_cornerBottomLeft.getColor().a < 255)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a +5));
                
                if(this->_cornerBottomRight.getColor().a < 255)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a +5));
                
                break;
            case 13 ... 14:
                if(this->_title.getFillColor().a > 0)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a -5));

                if(this->_nameText1.getFillColor().a > 0)
                    this->_nameText1.setFillColor(sf::Color(_nameText1.getFillColor().r, _nameText1.getFillColor().g, _nameText1.getFillColor().b, _nameText1.getFillColor().a -5));

                if(this->_andText.getFillColor().a > 0)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a -5));

                if(this->_nameText2.getFillColor().a > 0)
                    this->_nameText2.setFillColor(sf::Color(_nameText2.getFillColor().r, _nameText2.getFillColor().g, _nameText2.getFillColor().b, _nameText2.getFillColor().a -5));
                
                if(this->_cornerTopLeft.getColor().a > 0)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a -5));

                if(this->_cornerTopRight.getColor().a > 0)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a -5));
                
                if(this->_cornerBottomLeft.getColor().a > 0)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a -5));
                
                if(this->_cornerBottomRight.getColor().a > 0)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a -5));
                
                break;

            // Mentors
            case 15 ... 16:
                // set up
                this->_title.setString("Mentors");
                this->_title.setOrigin(this->_title.getLocalBounds().width/2, this->_title.getLocalBounds().height/2);

                this->_nameText1.setString(L"Srečko Zorman");
                this->_nameText1.setOrigin(this->_nameText1.getLocalBounds().width/2, this->_nameText1.getLocalBounds().height/2);

                this->_nameText2.setString("Rok Urbanc");
                this->_nameText2.setOrigin(this->_nameText2.getLocalBounds().width/2, this->_nameText2.getLocalBounds().height/2);
                // set up

                if(this->_title.getFillColor().a < 255)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a +5));
                
                if(this->_nameText1.getFillColor().a < 255)
                    this->_nameText1.setFillColor(sf::Color(_nameText1.getFillColor().r, _nameText1.getFillColor().g, _nameText1.getFillColor().b, _nameText1.getFillColor().a +5));

                if(this->_andText.getFillColor().a < 255)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a +5));

                if(this->_nameText2.getFillColor().a < 255)
                    this->_nameText2.setFillColor(sf::Color(_nameText2.getFillColor().r, _nameText2.getFillColor().g, _nameText2.getFillColor().b, _nameText2.getFillColor().a +5));
                
                if(this->_cornerTopLeft.getColor().a < 255)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a +5));

                if(this->_cornerTopRight.getColor().a < 255)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a +5));
                
                if(this->_cornerBottomLeft.getColor().a < 255)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a +5));
                
                if(this->_cornerBottomRight.getColor().a < 255)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a +5));
                
                break;
            case 18 ... 19:
                if(this->_title.getFillColor().a > 0)
                    this->_title.setFillColor(sf::Color(_title.getFillColor().r, _title.getFillColor().g, _title.getFillColor().b, _title.getFillColor().a -5));

                if(this->_nameText1.getFillColor().a > 0)
                    this->_nameText1.setFillColor(sf::Color(_nameText1.getFillColor().r, _nameText1.getFillColor().g, _nameText1.getFillColor().b, _nameText1.getFillColor().a -5));

                if(this->_andText.getFillColor().a > 0)
                    this->_andText.setFillColor(sf::Color(_andText.getFillColor().r, _andText.getFillColor().g, _andText.getFillColor().b, _andText.getFillColor().a -5));

                if(this->_nameText2.getFillColor().a > 0)
                    this->_nameText2.setFillColor(sf::Color(_nameText2.getFillColor().r, _nameText2.getFillColor().g, _nameText2.getFillColor().b, _nameText2.getFillColor().a -5));
                
                if(this->_cornerTopLeft.getColor().a > 0)
                    this->_cornerTopLeft.setColor(sf::Color(_cornerTopLeft.getColor().r, _cornerTopLeft.getColor().g, _cornerTopLeft.getColor().b, _cornerTopLeft.getColor().a -5));

                if(this->_cornerTopRight.getColor().a > 0)
                    this->_cornerTopRight.setColor(sf::Color(_cornerTopRight.getColor().r, _cornerTopRight.getColor().g, _cornerTopRight.getColor().b, _cornerTopRight.getColor().a -5));
                
                if(this->_cornerBottomLeft.getColor().a > 0)
                    this->_cornerBottomLeft.setColor(sf::Color(_cornerBottomLeft.getColor().r, _cornerBottomLeft.getColor().g, _cornerBottomLeft.getColor().b, _cornerBottomLeft.getColor().a -5));
                
                if(this->_cornerBottomRight.getColor().a > 0)
                    this->_cornerBottomRight.setColor(sf::Color(_cornerBottomRight.getColor().r, _cornerBottomRight.getColor().g, _cornerBottomRight.getColor().b, _cornerBottomRight.getColor().a -5));
                
                break;

            // School logo
            case 20 ... 21:
                if(this->_scvLogo.getColor().a < 255)
                    this->_scvLogo.setColor(sf::Color(_scvLogo.getColor().r, _scvLogo.getColor().g, _scvLogo.getColor().b, _scvLogo.getColor().a +5));
                
                if(this->_vssLogo.getColor().a < 255)
                    this->_vssLogo.setColor(sf::Color(_vssLogo.getColor().r, _vssLogo.getColor().g, _vssLogo.getColor().b, _vssLogo.getColor().a +5));
                break;
            case 23 ... 24:
                if(this->_scvLogo.getColor().a  > 0)
                    this->_scvLogo.setColor(sf::Color(_scvLogo.getColor().r, _scvLogo.getColor().g, _scvLogo.getColor().b, _scvLogo.getColor().a -5));
                
                if(this->_vssLogo.getColor().a  > 0)
                    this->_vssLogo.setColor(sf::Color(_vssLogo.getColor().r, _vssLogo.getColor().g, _vssLogo.getColor().b, _vssLogo.getColor().a -5));
                break;

            // Engin logo
            case 25 ... 26:
                if(this->_logo.getColor().a < 255)
                    this->_logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, _logo.getColor().a +5));
                break;
            case 28 ... 29:
                if(this->_logo.getColor().a  > 0)
                    this->_logo.setColor(sf::Color(_logo.getColor().r, _logo.getColor().g, _logo.getColor().b, _logo.getColor().a -5));
                break;

            case 30:
                this->_data->_sound.stop();

                //Switch to the Main Menu
                this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
                break;
        }
    }

    void EndState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);
        
        this->_data->window.draw(this->_theEnd);

        this->_data->window.draw(this->_title);

        this->_data->window.draw(this->_nameText1);
        this->_data->window.draw(this->_andText);
        this->_data->window.draw(this->_nameText2);

        this->_data->window.draw(this->_scvLogo);
        this->_data->window.draw(this->_vssLogo);

        this->_data->window.draw(this->_logo);

        this->_data->window.display();
    }
}
