#include "Button.hpp"

namespace Night_Rocket
{
    Button::Button(){}

    void Button::SetUp(sf::String text, const sf::Font& font, float fontSize, sf::Color color, const sf::Texture& texture, sf::Vector2f scale, sf::Vector2f position)
    {
        m_color = color;
        m_text.setFont(font);
        m_text.setString(text);
        m_text.setCharacterSize(fontSize);
        m_text.setFillColor(color);
        m_text.setOutlineColor(sf::Color::Black);
        m_text.setOutlineThickness(1);
        m_text.setOrigin(m_text.getGlobalBounds().width/2, m_text.getGlobalBounds().height/2);
        m_text.setPosition(position.x, position.y);

        if(m_flap){
            m_left.setTexture(texture);
            m_left.setOrigin(m_left.getGlobalBounds().width, m_left.getGlobalBounds().height/2);
            m_left.setScale(scale);
            m_left.scale(1,1);
            m_left.setPosition(position.x-(m_text.getGlobalBounds().width/2+10), position.y);

            m_right.setTexture(texture);
            m_right.setOrigin(m_right.getGlobalBounds().width, m_right.getGlobalBounds().height/2);
            m_right.setScale(scale);
            m_right.scale(-1,1);
            m_right.setPosition(position.x+(m_text.getGlobalBounds().width/2+10), position.y);
        }

        m_left.setColor(sf::Color(m_left.getColor().r, m_left.getColor().g, m_left.getColor().b , 0));
        m_right.setColor(sf::Color(m_right.getColor().r, m_right.getColor().g, m_right.getColor().b , 0));

        m_debugger.setSize(sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height));
        m_debugger.setOrigin(m_debugger.getGlobalBounds().width, m_debugger.getGlobalBounds().height);
        m_debugger.setPosition(m_text.getGlobalBounds().width + m_text.getGlobalBounds().left, m_text.getGlobalBounds().height + m_text.getGlobalBounds().top);

        m_debugger.setOutlineColor(sf::Color::Green);
        m_debugger.setFillColor(sf::Color::Transparent);
        m_debugger.setOutlineThickness(1);

        //std::cout << m_text.getGlobalBounds().width + m_text.getGlobalBounds().left << " " << m_text.getGlobalBounds().height + m_text.getGlobalBounds().top << std::endl;
        //std::cout << m_debugger.getPosition().x << " " << m_debugger.getPosition().y << std::endl;
    }

    sf::FloatRect Button::getLocalBounds() const
    {
        return m_text.getLocalBounds();
    }

    sf::FloatRect Button::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
    }

    void Button::setHover(bool hover)
    {
        m_hover = hover;
    }

    bool Button::getHover() const
    {
        return m_hover;
    }

    void Button::setDebug(bool debug)
    {
        m_debug = debug;
    }

    bool Button::getDebug() const
    {
        return m_debug;
    }

    void Button::setFlap(bool flap)
    {
        m_flap = flap;
    }

    bool Button::getFlap() const
    {
        return m_flap;
    }

     bool Button::isInObject(sf::Vector2i position)
     {
        sf::FloatRect temp(m_debugger.getPosition().x - m_debugger.getGlobalBounds().width, m_debugger.getPosition().y - m_debugger.getGlobalBounds().height, m_debugger.getGlobalBounds().width, m_debugger.getGlobalBounds().height);

        if(temp.contains(sf::Vector2f(position)))
        {
            return true;
        }

        return false;
     }

    void Button::update(sf::Time deltaTime)
    {
        if(m_hover)
        {
            if(m_left.getColor().a < 255 && m_right.getColor().a < 255){
                m_text.setFillColor(sf::Color::White);
                m_left.setColor(sf::Color(m_left.getColor().r, m_left.getColor().g, m_left.getColor().b , m_left.getColor().a+5));
                m_right.setColor(sf::Color(m_right.getColor().r, m_right.getColor().g, m_right.getColor().b , m_right.getColor().a+5));
            }
        }
        else{
            m_text.setFillColor(m_color);
            if(m_left.getColor().a > 5 && m_right.getColor().a > 5){
                m_left.setColor(sf::Color(m_left.getColor().r, m_left.getColor().g, m_left.getColor().b , m_left.getColor().a-5));
                m_right.setColor(sf::Color(m_right.getColor().r, m_right.getColor().g, m_right.getColor().b , m_right.getColor().a-5));
            }
            else if(m_left.getColor().a >= 5 && m_right.getColor().a >= 5)
            {
                m_left.setColor(sf::Color(m_left.getColor().r, m_left.getColor().g, m_left.getColor().b , 0));
                m_right.setColor(sf::Color(m_right.getColor().r, m_right.getColor().g, m_right.getColor().b , 0));
            }
        }
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_text);
        if(m_flap){
            target.draw(m_left);
            target.draw(m_right);
        }

        if(m_debug)
        {
            target.draw(m_debugger);
        }
    }
}
