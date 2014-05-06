#ifndef PONGIMAGES_H
#define PONGIMAGES_H
#include <math.h>  // Bunch of Libraries
#include <iostream>
#include <time.h>
#include <iomanip> // end of libiaries
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;


class ScreenBuild
    {

    public:
        ScreenBuild();
        ~ScreenBuild();
        void makeScreen();// this checks and prints the window.
        bool getSlider( bool );
        bool getBall( bool );
        void setSlider();
        void setOpponentSlider();
        void setBall();
        void moveSlider();
        void moveBall();

    private:
        int screenWidth;
        int screenHeight;
        int pngPics;

    };

//constructor

ScreenBuild::ScreenBuild()
    {

    screenWidth = 640;

    screenHeight = 480;

    }// scoreKeeper::scoreKeeper()

void ScreenBuild::makeScreen()
    {

    SDL_Window* screen = NULL;

    SDL_Surface* screenOutput = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {

        cout << "Error the SDL failed to start. Pong has exited." << endl;

        cout << "The type of error is:" << SDL_GetError() << endl;

        }// if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    else
        {

        screen = SDL_CreateWindow( "Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

        if( screen == NULL )
            {

            cout << " An error has a occured stopping the screen from printing." << endl;

            cout << "Pong is exiting. The error is:" << SDL_GetError() << endl;

            }// if( screen == NULL )

        else
            {

            pngPics = IMG_INIT_PNG;

            if( !( IMG_Init( pngPics ) & pngPics) )
                {

                cout << " Error: The slider was not found. " << endl;

                cout << IMG_GetError() << endl;

                }// if( !( IMG_Init( pngPics ) & pngPics) )

            else
                {

                screenOutput = SDL_GetWindowSurface( screen );

                }// else of if( !( IMG_Init( pngPics ) & pngPics) )

            /*screenOutput = SDL_GetWindowSurface( screen );

            SDL_FillRect( screenOutput, NULL, SDL_MapRGB( screenOutput -> format, 0xFF, 0xFF, 0xFF ) );

            SDL_UpdateWindowSurface( screen );

            SDL_Delay( 2000 );*/

            }// else of if( screen == NULL )

        }// else of if( SDL_Init( SDL_INIT_VIDEO ) < 0 )

    }// void ScreenBuild::makeWindow()

bool ScreenBuild::getSlider( bool )
    {



    }// bool ScreenBuild::getSlider( bool )

ScreenBuild::~ScreenBuild()
    {

    }// ScreenBuild::~ScreenBuild()

#endif // PONGIMAGES_H
