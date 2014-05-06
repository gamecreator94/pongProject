#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "pongImages.h"
#include "pongScoreKeeper.h"


using namespace std;

void winnerFunction( bool );
int main( int argc, char* args[] )
    {

    ScreenBuild game;

    game.makeScreen();

    return 0;

    }// int main( int argc, char* args[] )
