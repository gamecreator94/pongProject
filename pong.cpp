#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "pongImages.h"
#include "pongScoreKeeper.h"


using namespace std;

int main( int argc, char* args[] )
    {

    bool personPlayer = true;
    bool computerPlayer = true;
    bool gameOn = true;
    SDL_Window* screen;
    SDL_Surface* screenPrint;
    SDL_Surface* screenOutput;
    SDL_Surface* screenOutput2;
    SDL_Surface* screenOutput3;
    SDL_Event gameOver;
    ScreenBuild game;

    game.makeScreen();

    game.getSlider();

    screen = game.getScreen( screen );

    screenOutput = game.getGamePieces( screenOutput );

    game.getBall();

    screenOutput2 = game.getGamePieces( screenOutput );

    game.getenemySlider();

    screenOutput3 = game.getGamePieces( screenOutput );

    screenPrint = SDL_GetWindowSurface( screen );

    gameOn = game.gameWorks;

    // The three bool variables determines who wins, loses, or if you chose to quit.

    while( personPlayer && computerPlayer && gameOn )
        {

        //while( SDL_PollEvent( &gameOver ) != 0 )
            //{

            game.followSlider();

            game.followBall();

            game.followEnemySlider();

            SDL_FillRect(screenPrint, NULL, SDL_MapRGB(screenPrint -> format, 0x00, 0x00, 0x00));

            SDL_BlitSurface( screenOutput, NULL, screenPrint, &game.sliderRectangle );

            SDL_BlitSurface( screenOutput2, NULL, screenPrint, &game.ballRectangle );

            SDL_BlitSurface( screenOutput3, NULL, screenPrint, &game.EnemySliderRectangle );

            SDL_UpdateWindowSurface( screen );

            SDL_Delay(4);

            if( gameOver.type == SDL_QUIT )
                {

                gameOn = false;

                }// if( gameOver.type == SDL_QUIT )

            //}// while( SDL_PollEvent( &gameOver ) != 0 )

        }// while( personPlayer && computerPlayer )

    return 0;

    }// int main( int argc, char* args[] )
