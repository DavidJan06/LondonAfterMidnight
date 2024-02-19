#include "Detective.hpp"

namespace Night_Rocket
{
    Detective::Detective(){}

    void Detective::Init(GameDataRef Data, sf::Vector2i Position)
    {
        this->_data = Data;
        this->_data->assets.LoadTexture("Detective_Walk", DETECTIVE_WALK);
        this->_data->assets.LoadTexture("Detective_Interact", DETECTIVE_INTERACT);

        this->Idle.setSpriteSheet(this->_data->assets.GetTexture("Detective_Walk"));

        this->Idle.addFrame(sf::IntRect(0,0,800,800));

        this->Interact.setSpriteSheet(this->_data->assets.GetTexture("Detective_Interact"));

        this->Interact.addFrame(sf::IntRect(0,0,800,800));
        this->Interact.addFrame(sf::IntRect(800,0,800,800));
        this->Interact.addFrame(sf::IntRect(1600,0,800,800));
        this->Interact.addFrame(sf::IntRect(2400,0,800,800));
        this->Interact.addFrame(sf::IntRect(0,800,800,800));
        this->Interact.addFrame(sf::IntRect(800,800,800,800));
        this->Interact.addFrame(sf::IntRect(1600,800,800,800));
        this->Interact.addFrame(sf::IntRect(2400,800,800,800));
        this->Interact.addFrame(sf::IntRect(0,1600,800,800));
        this->Interact.addFrame(sf::IntRect(800,1600,800,800));
        this->Interact.addFrame(sf::IntRect(1600,1600,800,800));
        this->Interact.addFrame(sf::IntRect(2400,1600,800,800));
        //REVRT
        this->Interact.addFrame(sf::IntRect(2400,1600,800,800));
        this->Interact.addFrame(sf::IntRect(1600,1600,800,800));
        this->Interact.addFrame(sf::IntRect(800,1600,800,800));
        this->Interact.addFrame(sf::IntRect(0,1600,800,800));
        this->Interact.addFrame(sf::IntRect(2400,800,800,800));
        this->Interact.addFrame(sf::IntRect(1600,800,800,800));
        this->Interact.addFrame(sf::IntRect(800,800,800,800));
        this->Interact.addFrame(sf::IntRect(0,800,800,800));
        this->Interact.addFrame(sf::IntRect(2400,0,800,800));
        this->Interact.addFrame(sf::IntRect(1600,0,800,800));
        this->Interact.addFrame(sf::IntRect(800,0,800,800));
        this->Interact.addFrame(sf::IntRect(0,0,800,800));

        this->Walk.setSpriteSheet(this->_data->assets.GetTexture("Detective_Walk"));

        this->Walk.addFrame(sf::IntRect(800,0,800,800));
        this->Walk.addFrame(sf::IntRect(1600,0,800,800));
        this->Walk.addFrame(sf::IntRect(2400,0,800,800));
        this->Walk.addFrame(sf::IntRect(0,800,800,800));
        this->Walk.addFrame(sf::IntRect(800,800,800,800));
        this->Walk.addFrame(sf::IntRect(1600,800,800,800));
        this->Walk.addFrame(sf::IntRect(2400,800,800,800));
        this->Walk.addFrame(sf::IntRect(0,1600,800,800));
        this->Walk.addFrame(sf::IntRect(800,1600,800,800));
        this->Walk.addFrame(sf::IntRect(1600,1600,800,800));
        this->Walk.addFrame(sf::IntRect(2400,1600,800,800));
        this->Walk.addFrame(sf::IntRect(0,2400,800,800));
        this->Walk.addFrame(sf::IntRect(800,2400,800,800));
        this->Walk.addFrame(sf::IntRect(1600,2400,800,800));
        this->Walk.addFrame(sf::IntRect(2400,2400,800,800));
        this->Walk.addFrame(sf::IntRect(0,3200,800,800));

        this->_detective.play(this->Walk);
        this->_detective.setFrameTime(0.1f);
        this->setPosition(Position.x, Position.y); // Spremen
        this->setOrigin(this->_detective.getGlobalBounds().width/2 , this->_detective.getGlobalBounds().height);

        this->_speed = 2.0f;
        this->_isRight = true;
        this->_interact = false;
        this->_move = false;

        for(int i = 1; i <= 10; i++){
            this->_scaleMap.insert(std::pair<int, float>((835+24*i),(0.6+0.01*i)));
        }

        this->_scale= 0.65;
        this->_movePos = sf::Vector2i(Position.x, Position.y);
    }

    void Detective::HandleInput(sf::Event event, sf::View View)
    {
        if(sf::Event::MouseButtonPressed == event.type)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i r;
                r = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
                r = sf::Vector2i(this->_data->window.mapPixelToCoords(r, View));

                if(r.x > 0 && r.x < 1080 * OLD_ASPECT_RATIO){
                    _movePos = r;
                }
            }
        }
    }

    void Detective::Update(float dt)
    {
        //Animation Update
        this->_detective.Update(dt);

        //Set Sprite Direction
        if(this->_isRight == true){
            this->setScale(this->_scale,this->_scale);
        }
        else{
            this->setScale(-this->_scale,this->_scale);
        }

        //Movement Update
        float dx = this->_movePos.x - this->getPosition().x;
        float dy = this->_movePos.y - this->getPosition().y;

        float dist = sqrt(dx * dx + dy * dy);

        float xVelocity = 0;
        float yVelocity = 0;

        if(dist != 0){
            xVelocity = dx/dist;
            yVelocity = dy/dist;
        }

        this->_moveVector = sf::Vector2f(xVelocity, yVelocity);

        if(!this->_interact)
            if(((this->getPosition().x < this->_movePos.x-1) ||
                (this->getPosition().x > this->_movePos.x+1)) &&
                ((this->getPosition().y < this->_movePos.y-1) ||
                (this->getPosition().y > this->_movePos.y+1)) )
            {
                this->setPosition(this->getPosition().x + xVelocity * this->_speed, this->getPosition().y + yVelocity * this->_speed);
                this->_detective.play(this->Walk);
                this->_move = true;
            }
            else{
                this->_move = false;
            }
        
        if(this->_data->_selectedItem != nullptr || this->_interact)
        {
            sf::Vector2f _itemPos = sf::Vector2f(0,0);
            sf::Vector2f Calc = sf::Vector2f(0,0);
            float itemDist = 0;
            if(this->_data->_selectedItem != nullptr){
                _itemPos = static_cast<Item *>(this->_data->_selectedItem)->getInteractPos();
                //std::cout << "Position: "<< _itemPos.x  << ", "<< _itemPos.y << std::endl;
                Calc = this->getPosition() - _itemPos;
                itemDist = sqrt(Calc.x * Calc.x + Calc.y * Calc.y);
                //Left or Right
                if(Calc.x > 0)
                    this->_isRight = false;
                else
                    this->_isRight = true;
            }

            //printf("X: %f", Calc.x);
            //printf("Y: %f", Calc.y);
            //std::cout << itemDist << std::endl;

            // If to far from object
            if(itemDist < 200){
                this->_interact = true;
                this->_movePos.x = this->getPosition().x;
                this->_movePos.y = this->getPosition().y;

                this->_detective.play(this->Interact);

                if(_detective.getCurrentFrame() == 11){
                    if(this->_data->_selectedItem != nullptr)
                        static_cast<Item *>(this->_data->_selectedItem)->setPressed(true);
                }

                if(_detective.getAnimation()->getSize()-1 == _detective.getCurrentFrame()){
                    this->_interact = false;
                }
            }
            else{
                //printf("Can't Reach!\n");
                this->_data->_dialogueText = "Can't Reach!";
                this->_data->_selectedItem = nullptr;
                this->_interact = false;
            }
        }

        if(!this->_interact &&  !this->_move){
            this->_detective.play(this->Idle);
        }

        // Detect Direction
        if(!this->_interact && this->_move)
            if(xVelocity < 0)
            {
                if(this->_isRight == true)
                    this->_isRight = false;
            }
            else
            {
                if(this->_isRight == false)
                    this->_isRight = true;
            }

        //Set Bounds  -- need Fix
        if(this->_movePos.y < 835){
            this->_movePos.y = 835;
        }

        if(this->_movePos.y > 1080){
            this->_movePos.y = 1080;
        }

        if(this->_movePos.x < 0){
            this->_movePos.x = 0;
        }

        if(this->_movePos.x > 1080 * OLD_ASPECT_RATIO ){
            this->_movePos.x = 1080 * OLD_ASPECT_RATIO;
        }


        //Set Scale
        std::map<int, float>::iterator it = this->_scaleMap.begin();
        while(it != this->_scaleMap.end())
        {
            if( this->getPosition().y <= it->first)
            {
                this->_scale = it->second;
                break;
            }
            it++;
        }

    }

    void Detective::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(this->_detective, states);
    }

    sf::Vector2f Detective::getLocation(){
        return this->getPosition();
    }

    sf::Vector2f Detective::getMoveVector(){
        return this->_moveVector;
    }

    void Detective::setLocation(sf::Vector2i pos){
        this->setPosition(pos.x, pos.y);
    }

    void Detective::setMovePos(sf::Vector2i movePos){
        this->_movePos = movePos;
    }

}
