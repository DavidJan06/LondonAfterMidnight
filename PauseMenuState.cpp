#include "PauseMenuState.hpp"
#include "MainMenuState.hpp"
#include "SettingsState.hpp"
#include "ItemState.hpp"

namespace Night_Rocket
{
    PauseMenuState::PauseMenuState(GameDataRef data) : _data(data){}

    void PauseMenuState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24, 24, 24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        // Data loading
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);
        this->_data->assets.LoadTexture("Items", ITEMS);
        this->_data->assets.LoadTexture("Note", NOTE);

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

        // Buttons
        this->_resumeButton.SetUp("Resume", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::Black, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f, 0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y - this->_screen.getSize().y * 4/12));
        this->_settingsButton.SetUp("Settings", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::Black, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f, 0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y - this->_screen.getSize().y * 3/12));
        this->_exitButton.SetUp("Quit", this->_data->assets.GetFont("Nathan"), this->_screen.getSize().y / 20, sf::Color::Black, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f, 0.2f), sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y - this->_screen.getSize().y * 2/12 ));

        this->_resumeButton.setFlap(false);
        this->_settingsButton.setFlap(false);
        this->_exitButton.setFlap(false);

        //this->_resumeButton.setDebug(true);

        // Note background
        
        this->_note.setTexture(this->_data->assets.GetTexture("Note"));
        this->_note.setOrigin( this->_note.getGlobalBounds().width/2, this->_note.getGlobalBounds().height/2);
        this->_note.scale(0.7, 0.7);
        this->_note.setPosition(sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y));

        // Items
        this->_foto.setTexture(this->_data->assets.GetTexture("Items"));
        this->_foto.setTextureRect(sf::IntRect(0, 0, 600, 600));
        this->_foto.setOrigin( this->_foto.getGlobalBounds().width/2, this->_foto.getGlobalBounds().height/2);
        this->_foto.scale(0.5, 0.5);
        this->_foto.setPosition(sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y * 1/12 + 60));

        this->_gun.setTexture(this->_data->assets.GetTexture("Items"));
        this->_gun.setTextureRect(sf::IntRect(0, 600, 600, 600));
        this->_gun.setOrigin( this->_gun.getGlobalBounds().width/2, this->_gun.getGlobalBounds().height/2);
        this->_gun.scale(0.5, 0.5);
        this->_gun.setPosition(sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y * 4/12));
        this->_gun.setRotation(15.f);

        //Temp
        /*this->_tempFoto.setFillColor(sf::Color(24, 24, 24, 5));
        this->_tempFoto.setOutlineColor(sf::Color(0, 255, 0, 255));
        this->_tempFoto.setOutlineThickness(2);
        //this->_tempFoto.setScale(0.5, 0.5);

        this->_tempGun.setFillColor(sf::Color(24, 24, 24, 5));
        this->_tempGun.setOutlineColor(sf::Color(0, 255, 0, 255));
        this->_tempGun.setOutlineThickness(2);*/
    }

    void PauseMenuState::HandleInput()
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
                // Buttons
                if(this->_resumeButton.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_resumeButton.setHover(true);
                }
                else
                {
                    this->_resumeButton.setHover(false);
                }

                if(this->_settingsButton.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_settingsButton.setHover(true);
                }
                else
                {
                    this->_settingsButton.setHover(false);
                }

                if(this->_exitButton.isInObject(sf::Vector2i(event.mouseMove.x, event.mouseMove.y)))
                {
                    this->_exitButton.setHover(true);
                }
                else
                {
                    this->_exitButton.setHover(false);
                }

                // Images
                sf::FloatRect tempFoto(this->_foto.getPosition().x - this->_foto.getGlobalBounds().width/4, this->_foto.getPosition().y - this->_foto.getGlobalBounds().height/4, this->_foto.getGlobalBounds().width/2, this->_foto.getGlobalBounds().height/2);
                sf::FloatRect tempGun(this->_gun.getPosition().x - this->_gun.getGlobalBounds().width/4, this->_gun.getPosition().y - this->_gun.getGlobalBounds().height/4, this->_gun.getGlobalBounds().width/2, this->_gun.getGlobalBounds().height/2);

                /* Debug
                this->_tempFoto.setSize(sf::Vector2f(tempFoto.width, tempFoto.height));
                this->_tempFoto.setPosition(tempFoto.left, tempFoto.top);

                this->_tempGun.setSize(sf::Vector2f(tempGun.width, tempGun.height));
                this->_tempGun.setPosition(tempGun.left, tempGun.top);
                */

                sf::Vector2i _mousePos = sf::Mouse::getPosition();
                //_mousePos = sf::Vector2i(this->_data->window.mapPixelToCoords(_mousePos, this->_view));

                if(tempFoto.contains(sf::Vector2f(_mousePos)))
                {
                    this->_foto.setRotation(15.f);
                }
                else
                {
                    this->_foto.setRotation(0.f);
                }

                if(tempGun.contains(sf::Vector2f(_mousePos)))
                {
                    this->_gun.setRotation(15.f);
                }
                else
                {
                    this->_gun.setRotation(0.f);
                }
            }

            if(sf::Event::MouseButtonPressed == event.type)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if(this->_resumeButton.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_resumeButton.setHover(false);
                        this->_data->machine.RemoveState();
                    }

                    if(this->_settingsButton.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_settingsButton.setHover(false);
                        this->_data->machine.AddState(StateRef(new SettingsState(_data)), false);
                    }

                    if(this->_exitButton.isInObject(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))
                    {
                        this->_exitButton.setHover(false);
                        this->_data->window.close();
                    }

                    // Images
                    sf::FloatRect tempFoto(this->_foto.getPosition().x - this->_foto.getGlobalBounds().width/4, this->_foto.getPosition().y - this->_foto.getGlobalBounds().height/4, this->_foto.getGlobalBounds().width/2, this->_foto.getGlobalBounds().height/2);
                    sf::FloatRect tempGun(this->_gun.getPosition().x - this->_gun.getGlobalBounds().width/4, this->_gun.getPosition().y - this->_gun.getGlobalBounds().height/4, this->_gun.getGlobalBounds().width/2, this->_gun.getGlobalBounds().height/2);

                    sf::Vector2i _mousePos = sf::Mouse::getPosition();

                    if(tempFoto.contains(sf::Vector2f(_mousePos)))
                    {
                        if(this->_data->_foto_collected){
                            std::cout << "Click on Foto!" << std::endl;
                            this->_data->_displayedItem = 0;
                            this->_data->machine.AddState(StateRef(new ItemState(_data)), false);
                        }
                    }

                    if(tempGun.contains(sf::Vector2f(_mousePos)))
                    {
                        if(this->_data->_gun_collected){
                            std::cout << "Click on Gun!" << std::endl;
                            this->_data->_displayedItem = 1;
                            this->_data->machine.AddState(StateRef(new ItemState(_data)), false);
                        }
                    }
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.RemoveState();
            }
        }
    }

    void PauseMenuState::Update(float dt)
    {
        this->_resumeButton.update(sf::seconds(dt));
        this->_settingsButton.update(sf::seconds(dt));
        this->_exitButton.update(sf::seconds(dt));
    }

    void PauseMenuState::Draw(float dt)
    {
        //this->_data->window.clear(sf::Color(0, 0, 0, 0));
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_note);

        this->_data->window.draw(this->_resumeButton);
        this->_data->window.draw(this->_settingsButton);
        this->_data->window.draw(this->_exitButton);

        if(this->_data->_foto_collected)
            this->_data->window.draw(this->_foto);

        if(this->_data->_gun_collected)
            this->_data->window.draw(this->_gun);

        //this->_data->window.draw(this->_tempFoto);
        //this->_data->window.draw(this->_tempGun);

        this->_data->window.display();
    }
}

