#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "DEFINITIONS.hpp"

namespace Night_Rocket
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;

        void* _selectedItem;
        std::string _dialogueText = "";

        int _displayedItem = 0;

        bool _safe_opened = false;

        bool _foto_collected = false;
        bool _gun_collected = false;

        bool _letter = false;

        sf::Sound _sound;
        bool _soundOn = true;
        float _volume = 50;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game(int width, int height, std::string title);

    private:
        const float dt = 1.0f / 60.0f;
        sf::Clock _clock;

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };

}
