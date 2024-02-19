#include "SafeState.hpp"

namespace Night_Rocket
{
    SafeState::SafeState(GameDataRef data) : _data(data){}

    void SafeState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(this->_data->window.getSize().y * OLD_ASPECT_RATIO, this->_data->window.getSize().y));
        this->_screen.setFillColor(sf::Color(24, 24, 24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_data->window.getSize().x/2), (this->_data->window.getSize().y/2));

        this->_data->assets.LoadTexture("Items", ITEMS);
        this->_data->assets.LoadTexture("Corner", CORNER_IMAGE_SHORT);
        this->_data->assets.LoadFont("Nathan", FONT_NATHAN);

        this->_data->assets.LoadTexture("Lock0", LOCK0);
        this->_data->assets.LoadTexture("Lock1", LOCK1);
        this->_data->assets.LoadTexture("Lock2", LOCK2);
        this->_data->assets.LoadTexture("Lock3", LOCK3);
        this->_data->assets.LoadTexture("LockButton", LOCKBUTTON);
        this->_data->assets.LoadTexture("LockPlate", LOCKPLATE);

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

        //Lock
        this->_lockCenter = sf::Vector2f(this->_screen.getPosition().x, this->_screen.getPosition().y + 100);

        this->_lock_0_rot = rand() % 10;
        this->_lock_1_rot = rand() % 10;
        this->_lock_2_rot = rand() % 10;
        this->_lock_3_rot = rand() % 10;

        this->dir_0 = 1;
        this->dir_1 = 1;
        this->dir_2 = 1;
        this->dir_3 = 1;

        this->_lock_0.setTexture(this->_data->assets.GetTexture("Lock0"));
        this->_lock_0.setTextureRect(sf::IntRect(0, 0, 670, 670));
        this->_lock_0.setOrigin(this->_lock_0.getGlobalBounds().width/2, this->_lock_0.getGlobalBounds().height/2);
        //this->_lock_0.scale(1, 1);
        this->_lock_0.setPosition(this->_lockCenter.x, this->_lockCenter.y);
        this->_lock_0.setRotation(this->_lock_0_rot * 36);
        
        this->_lock_1.setTexture(this->_data->assets.GetTexture("Lock1"));
        this->_lock_1.setTextureRect(sf::IntRect(0, 0, 540, 540));
        this->_lock_1.setOrigin(this->_lock_1.getGlobalBounds().width/2, this->_lock_1.getGlobalBounds().height/2);
        //this->_lock_1.scale(0.8, 0.8);
        this->_lock_1.setPosition(this->_lockCenter.x, this->_lockCenter.y);
        this->_lock_1.setRotation(this->_lock_1_rot * 36);
        
        this->_lock_2.setTexture(this->_data->assets.GetTexture("Lock2"));
        this->_lock_2.setTextureRect(sf::IntRect(0, 0, 400, 400));
        this->_lock_2.setOrigin(this->_lock_2.getGlobalBounds().width/2, this->_lock_2.getGlobalBounds().height/2);
        //this->_lock_2.scale(0.6, 0.6);
        this->_lock_2.setPosition(this->_lockCenter.x, this->_lockCenter.y);
        this->_lock_2.setRotation(this->_lock_2_rot * 36);
        
        this->_lock_3.setTexture(this->_data->assets.GetTexture("Lock3"));
        this->_lock_3.setTextureRect(sf::IntRect(0, 0, 270, 270));
        this->_lock_3.setOrigin(this->_lock_3.getGlobalBounds().width/2, this->_lock_3.getGlobalBounds().height/2);
        //this->_lock_3.scale(0.4, 0.4);
        this->_lock_3.setPosition(this->_lockCenter.x, this->_lockCenter.y);
        this->_lock_3.setRotation(this->_lock_3_rot * 36);

        this->_lockButton.setTexture(this->_data->assets.GetTexture("LockButton"));
        this->_lockButton.setTextureRect(sf::IntRect(0, 0, 150, 150));
        this->_lockButton.setOrigin(this->_lockButton.getGlobalBounds().width/2, this->_lockButton.getGlobalBounds().height/2);
        //this->_lockButton.scale(0.2, 0.2);
        this->_lockButton.setPosition(this->_lockCenter.x, this->_lockCenter.y);

        this->_lockPlate.setTexture(this->_data->assets.GetTexture("LockPlate"));
        this->_lockPlate.setTextureRect(sf::IntRect(0, 0, 550, 190));
        this->_lockPlate.setOrigin(this->_lockPlate.getGlobalBounds().width/2, this->_lockPlate.getGlobalBounds().height/2);
        //this->_lockButton.scale(0.2, 0.2);
        this->_lockPlate.setPosition(this->_lockCenter.x, this->_lockCenter.y - 450);

        //DialogueText
        this->_dialogueText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_dialogueText.setString("");
        this->_dialogueText.setCharacterSize(42);
        this->_dialogueText.setFillColor(sf::Color::White);
        this->_dialogueText.setOutlineColor(sf::Color::Black);
        this->_dialogueText.setOutlineThickness(1);
        this->_dialogueText.setOrigin(this->_dialogueText.getGlobalBounds().width/2, this->_dialogueText.getGlobalBounds().height/2);
        this->_dialogueText.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);

        //Buttons
        this->_backButton.SetUp("Back", this->_data->assets.GetFont("Nathan"), 70, sf::Color::White, this->_data->assets.GetTexture("TwoShort"), sf::Vector2f(0.2f,0.2f), sf::Vector2f(sf::VideoMode::getDesktopMode().width/2, sf::VideoMode::getDesktopMode().height*11/12));
        //this->_backButton.setDebug(true);
    }

    void SafeState::HandleInput()
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

                    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition());
                    float distance = sqrt(pow(this->_lockCenter.x - mousePos.x, 2) + pow(this->_lockCenter.y - mousePos.y, 2) * 1.0);

                    if((distance < this->_lockButton.getGlobalBounds().width/2)){
                        //1 - 324
                        //9 - 36
                        //0 - 0
                        //1 - 324

                        std::cout << "Lock 0: " << this->_lock_0.getRotation() << std::endl;
                        std::cout << "Lock 1: " << this->_lock_1.getRotation() << std::endl;
                        std::cout << "Lock 2: " << this->_lock_2.getRotation() << std::endl;
                        std::cout << "Lock 3: " << this->_lock_3.getRotation() << std::endl;

                        if(this->_lock_0.getRotation() == 324
                        && this->_lock_1.getRotation() == 36
                        && this->_lock_2.getRotation() == 0
                        && this->_lock_3.getRotation() == 324){
                            this->_data->_safe_opened = true;
                            std::cout << "Opened" << std::endl;
                            this->_data->_dialogueText = "I got it. It is unlocked.";
                            //this->_data->machine.RemoveState();
                        }
                        else{
                            this->_data->_dialogueText = "Still locked. I need diffrent code.";
                        }
                    }
                }
            }

            
            if (sf::Event::MouseWheelMoved == event.type)
            {
                sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition());
                float distance = sqrt(pow(this->_lockCenter.x - mousePos.x, 2) + pow(this->_lockCenter.y - mousePos.y, 2) * 1.0);
                
                std::cout << "Distance: " << distance << std::endl;

                if((distance < 135) && !(distance < 75)){
                    this->_lock_3_rot += event.mouseWheel.delta;
                    dir_3 = (event.mouseWheel.delta > 0)? +1 : -1;

                    if(this->_lock_3_rot == 10) this->_lock_3_rot = 0;

                    if(this->_lock_3_rot == -1) this->_lock_3_rot = 9;
                }
                
                if((distance < 200) && !(distance < 135)){
                    this->_lock_2_rot += event.mouseWheel.delta;
                    dir_2 = (event.mouseWheel.delta > 0)? +1 : -1;

                    if(this->_lock_2_rot == 10) this->_lock_2_rot = 0;

                    if(this->_lock_2_rot == -1) this->_lock_2_rot = 9;
                }
                
                if((distance < 270) && !(distance < 200)){
                    this->_lock_1_rot += event.mouseWheel.delta;
                    dir_1 = (event.mouseWheel.delta > 0)? +1 : -1;

                    if(this->_lock_1_rot == 10) this->_lock_1_rot = 0;

                    if(this->_lock_1_rot == -1) this->_lock_1_rot = 9;
                }

                if((distance < 325) && !(distance < 270)){
                    this->_lock_0_rot += event.mouseWheel.delta;
                    dir_0 = (event.mouseWheel.delta > 0)? +1 : -1;

                    if(this->_lock_0_rot == 10) this->_lock_0_rot = 0;

                    if(this->_lock_0_rot == -1) this->_lock_0_rot = 9;
                }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.RemoveState();
            }
        }
    }

    void SafeState::Update(float dt)
    {
        //DialogueText
        if(this->_data->_dialogueText != ""){
            this->_dialogueText.setString(this->_data->_dialogueText);
            this->_data->_dialogueText = "";
            this->_clock.restart();
        }

        //Lock Rotate
        if(this->_lock_3.getRotation() != this->_lock_3_rot * 36)
            this->_lock_3.setRotation(round((this->_lock_3.getRotation() + 36 * dt * dir_3) * 100.0) / 100.0);

        if(this->_lock_2.getRotation() != this->_lock_2_rot * 36)
            this->_lock_2.setRotation(round((this->_lock_2.getRotation() + 36 * dt * dir_2) * 100.0) / 100.0);

        if(this->_lock_1.getRotation() != this->_lock_1_rot * 36)
            this->_lock_1.setRotation(round((this->_lock_1.getRotation() + 36 * dt * dir_1) * 100.0) / 100.0);

        if(this->_lock_0.getRotation() != this->_lock_0_rot * 36)
            this->_lock_0.setRotation(round((this->_lock_0.getRotation() + 36 * dt * dir_0) * 100.0) / 100.0);

        //Switch
        if(this->_clock.getElapsedTime().asSeconds() > 2){
            this->_dialogueText.setString("");

            if(this->_data->_safe_opened)
                this->_data->machine.RemoveState();
        }

        this->_dialogueText.setOrigin(this->_dialogueText.getGlobalBounds().width/2, this->_dialogueText.getGlobalBounds().height/2);
        //this->_dialogueText.setPosition(this->_detective.getLocation().x, this->_detective.getLocation().y - 500);

        //Button
        this->_backButton.update(sf::seconds(dt));
    }

    void SafeState::Draw(float dt)
    {
        //this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_cornerTopLeft);
        this->_data->window.draw(this->_cornerTopRight);
        this->_data->window.draw(this->_cornerBottomLeft);
        this->_data->window.draw(this->_cornerBottomRight);

        this->_data->window.draw(this->_lock_0);
        this->_data->window.draw(this->_lock_1);
        this->_data->window.draw(this->_lock_2);
        this->_data->window.draw(this->_lock_3);

        this->_data->window.draw(this->_lockButton);

        this->_data->window.draw(this->_lockPlate);

        this->_data->window.draw(this->_dialogueText);

        this->_data->window.draw(this->_backButton);

        this->_data->window.display();
    }
}
