#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include <iostream>

using namespace std;

class Character{
    SDL_Renderer * renderer;
    SDL_Texture * characterTexture;
    SDL_Surface * characterSurface;
    short int originalPositionX;
    short int originalPositionY;
    
    public:
        const char * characterName;
        const char * file;
        SDL_Rect * src, dest;

        Character(const char * characterName, const char * file, SDL_Renderer * renderer){
            this->characterName = characterName;
            this->file = file;
            this->renderer = renderer;
            this->originalPositionX = 64;
            this->originalPositionY = 64;

            this->defineCharacterSizeAndPosition();
        }

        void key(SDL_Event &event){
            if(event.type == 768){
                this->dest.x += 1;

                cout << this->dest.x << endl;
                this->file = "./right-player.bmp";

                this->renderCharacter();
            }
        }
            
    SDL_Texture * getCharacter(){
        if(this->renderer){
            this->characterSurface = IMG_Load(this->file);
            this->characterTexture = SDL_CreateTextureFromSurface(this->renderer, this->characterSurface);
            SDL_FreeSurface(this->characterSurface);
        }

        return this->characterTexture;
    }

    void defineCharacterSizeAndPosition(){
        this->dest.h = this->originalPositionX;
        this->dest.w = this->originalPositionY;
        this->dest.x = this->originalPositionX;
        this->dest.y = this->originalPositionY;
    }

    void renderCharacter(){
        cout << "Renderer: " << this->renderer << "Character: " << this->getCharacter() << "Dest: " << &this->dest << " | " << endl;
        SDL_RenderCopy(this->renderer, this->getCharacter(), NULL, &this->dest);
    }
};

#endif