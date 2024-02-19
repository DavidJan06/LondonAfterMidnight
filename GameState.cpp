#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "PauseMenuState.hpp"
#include "SafeState.hpp"
#include "LetterState.hpp"
#include "EndState.hpp"

namespace Night_Rocket
{
    GameState::GameState(GameDataRef data) : _data(data){}

    void GameState::Init()
    {
        //Screen
        this->_screen.setSize(sf::Vector2f(1080 * OLD_ASPECT_RATIO, 1080));
        this->_screen.setFillColor(sf::Color(24,24,24));
        this->_screen.setOrigin(this->_screen.getLocalBounds().width/2, this->_screen.getLocalBounds().height/2);
        this->_screen.setPosition((this->_screen.getSize().x/2), (this->_data->window.getSize().y/2));

        //View
        this->_view.setSize(sf::Vector2f(1080 * OLD_ASPECT_RATIO, 1080)); // set size of what is seen
        this->_view.setCenter((this->_view.getSize().x/2), (this->_data->window.getSize().y/2)); // set position on what is seen
        this->_view.setViewport(sf::FloatRect((1 - ((this->_data->window.getSize().y*OLD_ASPECT_RATIO)/this->_data->window.getSize().x))/2, 0, (this->_data->window.getSize().y*OLD_ASPECT_RATIO)/this->_data->window.getSize().x, 1)); // set pozition and size of view

        //Dekleracija stvari na zaslonu
        this->_data->assets.LoadFont("Nathan", FONT_NATHAN);
        this->_data->assets.LoadTexture("Office", ROOM_OFFICE);

        //Room background
        this->_roomInside.setTexture(this->_data->assets.GetTexture("Office"));
        this->_roomInside.setOrigin(this->_roomInside.getGlobalBounds().width/2, this->_roomInside.getGlobalBounds().height/2);
        this->_roomInside.setScale(this->_screen.getSize().x/this->_roomInside.getGlobalBounds().width, this->_screen.getSize().y/this->_roomInside.getGlobalBounds().height);
        this->_roomInside.setPosition(this->_screen.getPosition().x, this->_screen.getPosition().y);

        //Detective
        this->_detective.Init(this->_data, sf::Vector2i(200, 950));

        //Items
        this->_safe.Init(_data, SAFE, "gun", sf::Vector2i(219, 195), sf::Vector2i(this->_screen.getPosition().x  - this->_screen.getSize().y*2/7.2, this->_screen.getPosition().y), 0.5, 4, false, &this->_data->_gun_collected, sf::Vector2i(this->_screen.getPosition().x  - this->_screen.getSize().y*2/7.2, 835));
        this->_armchair.Init(_data, ARMCHAIR, "photo", sf::Vector2i(597, 845), sf::Vector2i(this->_screen.getPosition().x  + this->_screen.getSize().y/2, this->_screen.getPosition().y + this->_screen.getSize().y/6), 0.5, 2, false, &this->_data->_foto_collected, sf::Vector2i(1200, this->_screen.getPosition().y + this->_screen.getSize().y/6));
        this->_table.Init(_data, TABLE, "table", sf::Vector2i(1236, 825), sf::Vector2i(this->_screen.getPosition().x, this->_screen.getPosition().y + this->_screen.getSize().y/4), 0.5, 2, true, nullptr, sf::Vector2i(495, 995));
        
        this->_calendar.Init(_data, CALENDAR, "calendar", sf::Vector2i(116, 130), sf::Vector2i(this->_screen.getPosition().x  + this->_screen.getSize().y*2/7.2, this->_screen.getPosition().y), 0.5, 1, true, nullptr, sf::Vector2i(this->_screen.getPosition().x  + this->_screen.getSize().y*2/7.2, 835));
        this->_globe.Init(_data, GLOBE, "globe", sf::Vector2i(273, 577), sf::Vector2i(this->_screen.getPosition().x  + this->_screen.getSize().x * 1/7, this->_screen.getSize().y * 7.7/12), 0.5, 1, true, nullptr, sf::Vector2i(this->_screen.getPosition().x  + this->_screen.getSize().x * 1/7, this->_screen.getSize().y * 7.7/12));
        this->_chandelier.Init(_data, CHANDELIER, "chandelier", sf::Vector2i(600, 700), sf::Vector2i(this->_screen.getPosition().x, 175), 0.5, 1, true, nullptr, sf::Vector2i(this->_screen.getPosition().x, 0));

        //Item Collisions
        this->_table.setCollisionShape(sf::Vector2f(this->_table.getPos().x + 40, this->_table.getPos().y + 270), sf::Vector2f(this->_table.getSize().x -90, this->_table.getSize().y -270));
        this->_armchair.setCollisionShape(sf::Vector2f(this->_armchair.getPos().x + 0, this->_armchair.getPos().y - 0), sf::Vector2f(this->_armchair.getSize().x -0, this->_armchair.getSize().y -0));
        this->_globe.setCollisionShape(sf::Vector2f(this->_globe.getPos().x + 0, this->_globe.getPos().y + 0), sf::Vector2f(this->_globe.getSize().x -0, this->_globe.getSize().y -0));
        
        //Button Notebook
        this->_data->assets.LoadTexture("Notebook", NOTE_CLOSED);
        this->_notebook.setTexture(this->_data->assets.GetTexture("Notebook"));
        this->_notebook.setOrigin(this->_notebook.getGlobalBounds().width/2, this->_notebook.getGlobalBounds().height/2);
        this->_notebook.scale(0.125, 0.125);
        this->_notebook.setPosition(this->_notebook.getGlobalBounds().width/2 + 10, this->_notebook.getGlobalBounds().height/2 + 10);

        //Music
        this->_data->assets.LoadSoundBuffer("Game", GAME);
        this->_data->_sound.setBuffer(this->_data->assets.GetSoundBuffer("Game"));
        if(this->_data->_soundOn){
            this->_data->_sound.play();
        }
        this->_data->_sound.setLoop(true);
        this->_data->_sound.setVolume(this->_data->_volume);

        //DialogueText
        this->_dialogueText.setFont(this->_data->assets.GetFont("Nathan"));
        this->_dialogueText.setString("");
        this->_dialogueText.setCharacterSize(42); //85
        this->_dialogueText.setFillColor(sf::Color::White);
        this->_dialogueText.setOutlineColor(sf::Color::Black);
        this->_dialogueText.setOutlineThickness(1);
        this->_dialogueText.setOrigin(this->_dialogueText.getGlobalBounds().width/2, this->_dialogueText.getGlobalBounds().height/2);
        this->_dialogueText.setPosition(this->_detective.getLocation().x, this->_detective.getLocation().y);

        //Door
        this->_doorShape =  sf::FloatRect(sf::Vector2f(0, 160), sf::Vector2f(70, 700));

        //Collision List
        this->_collisionList.push_back(this->_table.getCollisionShape());
        this->_collisionList.push_back(this->_armchair.getCollisionShape());
        this->_collisionList.push_back(this->_globe.getCollisionShape());
        this->_collisionList.push_back(&this->_doorShape);

        //Reset Data
        
        this->_data->_displayedItem = 0;

        this->_data->_safe_opened = false;

        this->_data->_foto_collected = false;
        this->_data->_gun_collected = false;

        this->_data->_letter = false;
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_data->machine.AddState(StateRef(new PauseMenuState(_data)), false);
            }

            if(sf::Event::MouseMoved == event.type)
            {
                sf::FloatRect temp(this->_notebook.getPosition().x - this->_notebook.getGlobalBounds().width/2, this->_notebook.getPosition().y - this->_notebook.getGlobalBounds().height/2, this->_notebook.getPosition().x + this->_notebook.getGlobalBounds().width/2, this->_notebook.getPosition().y + this->_notebook.getGlobalBounds().height/2);

                sf::Vector2i _mousePos = sf::Mouse::getPosition();
                _mousePos = sf::Vector2i(this->_data->window.mapPixelToCoords(_mousePos, this->_view));

                if(temp.contains(sf::Vector2f(_mousePos)))
                {
                    this->_notebook.setRotation(15.f);
                }
                else
                {
                    this->_notebook.setRotation(0.f);
                }
            }

            bool UIclick = false;

            if(sf::Event::MouseButtonPressed == event.type)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i _mousePos = sf::Mouse::getPosition();
                    _mousePos = sf::Vector2i(this->_data->window.mapPixelToCoords(_mousePos, this->_view));

                    if((_mousePos.x > this->_notebook.getPosition().x - this->_notebook.getGlobalBounds().width/2) &&
                    (_mousePos.x < this->_notebook.getPosition().x + this->_notebook.getGlobalBounds().width/2) &&
                    (_mousePos.y > this->_notebook.getPosition().y - this->_notebook.getGlobalBounds().height/2) &&
                    (_mousePos.y < this->_notebook.getPosition().y + this->_notebook.getGlobalBounds().height/2))
                    {
                        this->_data->machine.AddState(StateRef(new PauseMenuState(_data)), false);
                        UIclick = true;
                    }
                }

                if(event.mouseButton.button == sf::Mouse::Right){
                    sf::Vector2i _mousePos = sf::Mouse::getPosition();
                    _mousePos = sf::Vector2i(this->_data->window.mapPixelToCoords(_mousePos, this->_view));

                    if(this->_doorShape.contains(sf::Vector2f(_mousePos))){
                        sf::Vector2f _itemPos = sf::Vector2f(this->_doorShape.left + this->_doorShape.width/2, this->_doorShape.top + this->_doorShape.height);
                        sf::Vector2f Calc = sf::Vector2f(0,0);
                        Calc = this->_detective.getPosition() - _itemPos;
                        float dist = sqrt(Calc.x * Calc.x + Calc.y * Calc.y);

                        if(dist < 200){
                            if(this->_data->_gun_collected){
                                this->_data->_sound.stop();
                                this->_data->_sound.setLoop(false);
                                this->_data->machine.AddState(StateRef(new EndState(_data)), true);
                                UIclick = true;
                            }
                            else{
                                this->_data->_dialogueText = "Can't leave.";
                            }
                        }
                    }
                }
            }

            if(!UIclick){
                this->_detective.HandleInput(event, this->_view);
                this->_safe.HandleInput(event, this->_view);
                this->_armchair.HandleInput(event, this->_view);
                this->_table.HandleInput(event, this->_view);
                this->_calendar.HandleInput(event, this->_view);
                this->_globe.HandleInput(event, this->_view);
            }
        }

    }

    void GameState::Update(float dt)
    {
        if(!this->_data->_letter){
            this->_data->machine.AddState(StateRef(new LetterState(_data)), false);
        }

        //DialogueText
        if(this->_data->_dialogueText != ""){
            this->_dialogueText.setString(this->_data->_dialogueText);
            this->_data->_dialogueText = "";
            this->_clock.restart();
        }

        if(this->_clock.getElapsedTime().asSeconds() > 5)
            this->_dialogueText.setString("");

        this->_dialogueText.setOrigin(this->_dialogueText.getGlobalBounds().width/2, this->_dialogueText.getGlobalBounds().height/2);
        this->_dialogueText.setPosition(this->_detective.getLocation().x, this->_detective.getLocation().y - 500);

        //Item Logic

        if(this->_armchair.changed){
            switch (this->_armchair.getSpriteNum())
            {
            case 1: // empty pocket
                this->_data->_dialogueText = "I found a photo.";
                break;
            }

            this->_armchair.changed = false;
        }

        if(this->_safe.changed){
            switch (this->_safe.getSpriteNum())
            {

            case 1: // Closed Safe
                this->_data->_dialogueText = "I need code to open it.";
                break;

            case 2: // Open Safe
                if(!this->_data->_safe_opened){
                    this->_safe.setSpriteNum(1);
                    this->_data->machine.AddState(StateRef(new SafeState(_data)), false);
                }
                else{
                    this->_data->_dialogueText = "What have we here?";
                }
                break;

            case 3: // Empty Safe
                this->_data->_dialogueText = " I found a gun. \nNow I can leave.";
                break;
            }

            this->_safe.changed = false;
        }

        if(this->_table.changed){
            switch (this->_table.getSpriteNum())
            {
            case 0: // Light on
                this->_data->_dialogueText = "Light on.";
                break;

            case 1: // Light off
                this->_data->_dialogueText = "Light off.";
                break;
            }

            this->_table.changed = false;
        }

        if(this->_calendar.changed){
            switch (this->_calendar.getSpriteNum())
            {
            case 0:
                this->_data->_dialogueText = "It's still set on the date of murder.";
                break;
            }

            this->_calendar.changed = false;
        }

        if(this->_globe.changed){
            switch (this->_globe.getSpriteNum())
            {
            case 0:
                switch (rand() % 4)
                {
                case 0:
                    this->_data->_dialogueText = "I have similar at home.";
                    break;
                case 1:
                    this->_data->_dialogueText = "I think someone forgot to draw Africa.";
                    break;
                case 2:
                    this->_data->_dialogueText = "        Always wanted to travel,        \nbut my boss won't give me vacation days.";
                    break;
                case 3:
                    this->_data->_dialogueText = "      *points finger*       \nI would like to travel here.";
                    break;
                }
                
                break;
            }

            this->_globe.changed = false;
        }

        // Updates
        this->_detective.Update(dt);
        this->_safe.Update(dt);
        this->_armchair.Update(dt);
        this->_table.Update(dt);
        this->_calendar.Update(dt);
        this->_globe.Update(dt);

        // Detective Collision
        for(sf::FloatRect* collision: _collisionList) {
            if(collision->contains(this->_detective.getLocation())){
                float top = this->_detective.getLocation().y - collision->top;
                float bottom = this->_detective.getLocation().y - (collision->top + collision->height);

                float left = this->_detective.getLocation().x - collision->left;
                float right = this->_detective.getLocation().x - (collision->left + collision->width);

                std::cout << "Top: " <<  top << std::endl;
                std::cout << "Bottom: " <<  bottom << std::endl;
                std::cout << "Left: " <<  left << std::endl;
                std::cout << "Right: " <<  right << std::endl;

                if(top < 2) //y - 2
                    this->_detective.setLocation(sf::Vector2i(this->_detective.getLocation().x, this->_detective.getLocation().y - 2));

                if(bottom > -2) //y + 2
                    this->_detective.setLocation(sf::Vector2i(this->_detective.getLocation().x, this->_detective.getLocation().y + 2));

                if(left < 2) //x - 2
                    this->_detective.setLocation(sf::Vector2i(this->_detective.getLocation().x - 2, this->_detective.getLocation().y));

                if(right > -2) //y + 2
                    this->_detective.setLocation(sf::Vector2i(this->_detective.getLocation().x + 2, this->_detective.getLocation().y));

                //std::cout << "In Object" << std::endl;
                //std::cout << "X: " << this->_detective.getMoveVector().x << "Y: " << this->_detective.getMoveVector().y << std::endl;
                //this->_detective.setLocation(sf::Vector2i(this->_detective.getLocation().x + (-this->_detective.getMoveVector().x * 2), this->_detective.getLocation().y + (-this->_detective.getMoveVector().y * 2)));
                this->_detective.setMovePos(sf::Vector2i(this->_detective.getLocation()));
            }
        }
    }

    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);

        this->_data->window.setView(this->_view);

        this->_data->window.draw(this->_screen);

        this->_data->window.draw(this->_roomInside);

        this->_data->window.draw(_safe);
        this->_data->window.draw(_armchair);

        this->_data->window.draw(_calendar);
        this->_data->window.draw(_globe);
        this->_data->window.draw(_chandelier);

        if(_detective.getPosition().y < /*_table.getPosition().y*/1000){
            this->_data->window.draw(_detective);
            this->_data->window.draw(_table);
            //printf("%f %f\n",_detective.getPosition().y, _table.getPosition().y );
        }
        else{
            this->_data->window.draw(_table);
            this->_data->window.draw(_detective);
            //printf("%f %f\n",_detective.getPosition().y, _table.getPosition().y);
        }

        //Debug Shape
        for(sf::FloatRect* collision: _collisionList) {
            this->_debugShape.setPosition(sf::Vector2f(collision->left, collision->top));
            this->_debugShape.setSize(sf::Vector2f(collision->width, collision->height));
            this->_debugShape.setOutlineThickness(1);
            this->_debugShape.setOutlineColor(sf::Color::Green);
            this->_debugShape.setFillColor(sf::Color::Transparent);

            //this->_data->window.draw(this->_debugShape);
        }

        //Buttons
        this->_data->window.draw(this->_notebook);

        //DialogueText
        this->_data->window.draw(this->_dialogueText);

        this->_data->window.setView(this->_data->window.getDefaultView());

        this->_data->window.display();
    }
}
