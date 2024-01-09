#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>

#include "./Game.cpp"

#include <iostream>
using namespace std;

class Player{
    SDL_Renderer * renderer;
    SDL_Texture * playerTexture;
    SDL_Surface * playerSurface;
    
    public:
        const char * file;

        Player(const char * file, SDL_Renderer * renderer){
            this->file = file;
            this->renderer = renderer;
        }

        SDL_Texture * getPlayer(){
            if(this->renderer){
                this->playerSurface = IMG_Load(this->file);
                this->playerTexture = SDL_CreateTextureFromSurface(this->renderer, this->playerSurface);
                SDL_FreeSurface(this->playerSurface);
            }

            return this->playerTexture;
        }
};

#endif