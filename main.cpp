#include <windows.h>
#include <winver.h>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{
    int ar = 0;

    while(true){

        std::cout<<"Select aspect ratio:\n";
        std::cout<<"(1) 16:10\n";
        std::cout<<"(2) 16:9\n";
        std::cout<<"(3) 4:3\n";
        std::cout<<"(4) other\n";
        std::cout<<"(5) my screen\n";
        std::cout<<"Select:";
        std::cin>>ar;

        if(ar != 0 && ar > 0 && ar <6){
            system("CLS");
            break;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n"<<"Press Enter to Continue.\n";
            std::getchar();
            system("CLS");
        }
    }

    int res = 0;
    int width;
    int height;
    while(true){

        std::cout<<"Select video resolution:\n";
        switch(ar){
            case 1:
            std::cout<<"(1) 1920 x 1200\n";
            std::cout<<"(2) 1680 x 1050\n";
            std::cout<<"(3) 1440 x 900\n";
            std::cout<<"(4) 1280 x 800\n";
            std::cout<<"Select:";
            std::cin>>res;
            break;

            case 2:
            std::cout<<"(1) 1920 x 1080\n";
            std::cout<<"(2) 1600 x 900\n";
            std::cout<<"(3) 1280 x 720\n";
            std::cout<<"(4) 640 x 360\n";
            std::cout<<"Select:";
            std::cin>>res;
            break;

            case 3:
            std::cout<<"(1) 1024 x 768\n";
            std::cout<<"(2) 800 x 600\n";
            std::cout<<"Select:";
            std::cin>>res;
            break;

            case 4:
            res = 4;
            break;

            case 5:
            res = 5;
            break;
        }

        if(res != 0 && res > 0 && res <6){
            switch(ar){
                case 1:
                switch(res){
                    case 1:
                    width = 1920;
                    height = 1200;
                    break;

                    case 2:
                    width = 1680;
                    height = 1050;
                    break;

                    case 3:
                    width = 1440;
                    height = 900;
                    break;

                    case 4:
                    width = 1280;
                    height = 800;
                    break;
                }
                break;

                case 2:
                switch(res){
                    case 1:
                    width = 1920;
                    height = 1080;
                    break;

                    case 2:
                    width = 1600;
                    height = 900;
                    break;

                    case 3:
                    width = 1280;
                    height = 720;
                    break;

                    case 4:
                    width = 640;
                    height = 360;
                    break;
                }
                break;

                case 3:
                switch(res){
                    case 1:
                    width = 1024;
                    height = 768;
                    break;

                    case 2:
                    width = 800;
                    height = 600;
                    break;

                }
                break;

                case 4:
                std::cout<<"Width:";
                std::cin>>width;
                std::cout<<"Height:";
                std::cin>>height;
                break;

                case 5:
                width = sf::VideoMode::getDesktopMode().width;
                height = sf::VideoMode::getDesktopMode().height;
                break;
            }

            system("CLS");
            break;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n"<<"Press Enter to Continue.\n";
            std::getchar();
            system("CLS");
        }
    }

    //Night_Rocket::Game(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, "London After Midnight");
    Night_Rocket::Game(width, height, "London After Midnight");

    //system("pause");
    return EXIT_SUCCESS;
}