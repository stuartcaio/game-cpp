#ifndef GAME_H
#define GAME_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "./Player.cpp"
#include "./Character.cpp"

#include <iostream>
using namespace std;

class Game{
    public:
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Event e;
        bool isRunning;

    void run(){
        this->isRunning = true;
        this->initWindow();

        if(!this->isRunning){
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }

    void initWindow(){
        SDL_Init(SDL_INIT_EVERYTHING);
        this->window = SDL_CreateWindow("My first game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600, false);

        if(this->isRunning){
            this->render();
        }
    }

    void render(){
        this->renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
        SDL_RenderClear(this->renderer);

        Character character("player", "./player.png", this->renderer);
        character.renderCharacter();

        SDL_RenderPresent(this->renderer);

        this->checkEvent(character);
    }

    void checkEvent(Character &character){
        while(this->isRunning == true){
            while(SDL_PollEvent(&e) != 0){
                if(e.type == SDL_QUIT){
                    this->isRunning = false;
                }

                character.key(e);
            }
        }
    }
};

#endif