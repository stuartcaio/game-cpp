#include <iostream>
#include <SDL2/SDL.h>
#include "./Game.cpp"
#include "./Character.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    Game game;
    game.run();

    return 0;
}