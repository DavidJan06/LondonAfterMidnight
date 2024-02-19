#include "AssetManager.hpp"

namespace Night_Rocket
{
    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;

        if( tex.loadFromFile(fileName))
        {
            this->_textures[name] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return this->_textures.at( name );
    }

    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        if( font.loadFromFile(fileName))
        {
            this->_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name)
    {
        return this->_fonts.at( name );
    }

    void AssetManager::LoadSoundBuffer(std::string name, std::string fileName)
    {
        sf::SoundBuffer soundbuffer;

        if( soundbuffer.loadFromFile(fileName))
        {
            this->_soundbuffer[name] = soundbuffer;
        }
    }

    sf::SoundBuffer &AssetManager::GetSoundBuffer(std::string name)
    {
        return this->_soundbuffer.at( name );
    }

}
