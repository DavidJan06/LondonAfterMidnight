#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Night_Rocket
{
    class AssetManager
    {
    public:
        AssetManager(){}
        ~AssetManager(){}

        void LoadTexture( std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);

        void LoadFont( std::string name, std::string fileName);
        sf::Font &GetFont(std::string name);

        void LoadSoundBuffer( std::string name, std::string fileName);
        sf::SoundBuffer &GetSoundBuffer(std::string name);

    private:
        std::map<std::string, sf::Texture > _textures;
        std::map<std::string, sf::Font > _fonts;
        std::map<std::string, sf::SoundBuffer > _soundbuffer;
    };
}
