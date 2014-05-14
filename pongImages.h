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
        ScreenBuild();// constructor
        ~ScreenBuild();// destructor
        void makeScreen();// this checks and prints the window.
        void getSlider();// checks if the slider is there then inserts om the left side.
        void getBall();// checks if the ball is there then inserts it between the sliders.
        void getenemySlider();// checks if the enemy slider is there then inserts it on the right side.
        SDL_Window* getScreen( SDL_Window* );// moves the screen information to the main
        SDL_Surface* getGamePieces( SDL_Surface* );// determines which piece is placed in each spot.
        void followSlider();// Tracks the movements of the slider and allows the player to move the slider.
        void followEnemySlider();//Tracks the enemy slider and makes it follow the slider until the randomizer makes it miss.
        void followBall();// follows the ball and determines where it will go also checks if it has gone out of bounds.
        SDL_Rect sliderRectangle;
        SDL_Rect ballRectangle;
        SDL_Rect EnemySliderRectangle;
        bool gameWorks;

    private:
        int screenWidth;
        int screenHeight;
        int sliderY;
        int enemySliderY;
        int ballY;
        int ballX;
        int bitPics;
        int enemyMissBall;
        bool ballVertical;
        bool ballHorizontal;
        bool ballCanMoveVertically;
        bool ballCanMoveHorizontally;
        SDL_Window* screen;
        SDL_Surface* screenPrint;
        SDL_Surface* screenOutput;

    };

//constructor

ScreenBuild::ScreenBuild()
    {

    screenWidth = 640;

    screenHeight = 480;

    sliderY = 200;

    enemySliderY = 200;

    ballY = 240;

    ballX = 290;

    bitPics = 0;

    enemyMissBall = 0;

    gameWorks = true;

    SDL_Window* screen = NULL;

    screenPrint = NULL;

    SDL_Surface* screenOutput = NULL;

    sliderRectangle.x = 16;

    sliderRectangle.y = sliderY;

    EnemySliderRectangle.x = 568;

    EnemySliderRectangle.y = enemySliderY - 25;

    ballRectangle.x = ballX;

    ballRectangle.y = ballY;

    ballVertical = false;

    ballHorizontal = true;

    ballCanMoveVertically = false;

    ballCanMoveHorizontally = true;

    }// scoreKeeper::scoreKeeper()

void ScreenBuild::makeScreen()
    {

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        {

        cout << "Error the SDL failed to start. Pong has exited." << endl;

        cout << "The type of error is:" << SDL_GetError() << endl;

        gameWorks = false;

        }// if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    else
        {

        screen = SDL_CreateWindow( "Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

        if( screen == NULL )
            {

            cout << " An error has a occured stopping the screen from printing." << endl;

            cout << "Pong is exiting. The error is:" << SDL_GetError() << endl;

            gameWorks = false;

            }// if( screen == NULL )

        }// else of if( SDL_Init( SDL_INIT_VIDEO ) < 0 )

    }// void ScreenBuild::makeWindow()

void ScreenBuild::getSlider()
    {

    if( gameWorks )
        {

        screenOutput = SDL_LoadBMP( "pongSlider.bmp" );

        if( screenOutput == NULL )
            {

            cout << " An error occured stopping the image from loading. " << endl;

            cout << " The error is: " << SDL_GetError();

            gameWorks = false;

            }// if( screenOutput == NULL )

        }// if( gameWorks )

    }// void ScreenBuild::getSlider()

void ScreenBuild::getBall()
    {

        if( gameWorks )
        {

        screenOutput = SDL_LoadBMP( "pongBall.bmp" );

        if( screenOutput == NULL )
            {

            cout << " An error occured stopping the image from loading. " << endl;

            cout << " The error is: " << SDL_GetError();

            gameWorks = false;

            }// if( screenOutput == NULL )

        }// if( gameWorks )

    }// void ScreenBuild::getBall()

void ScreenBuild::getenemySlider()
    {

    if( gameWorks )
        {

        screenOutput = SDL_LoadBMP( "pongSlider.bmp" );

        if( screenOutput == NULL )
            {

            cout << " An error occured stopping the image from loading. " << endl;

            cout << " The error is: " << SDL_GetError();

            gameWorks = false;

            }// if( screenOutput == NULL )

        }// if( gameWorks )

    }// void ScreenBuild::getenemySlider()

SDL_Window* ScreenBuild::getScreen( SDL_Window* useScreen )
    {

    useScreen = screen;

    return useScreen;

    }// SDL_Window ScreenBuild::getScreen( SDL_Window useScreen )

SDL_Surface* ScreenBuild::getGamePieces( SDL_Surface* useScreenOutput )
    {

    switch(bitPics)
        {

        case(0):
            useScreenOutput = screenOutput;
            bitPics = 1;
            break;

        case(1):
            useScreenOutput = screenOutput;
            bitPics = 0;
            break;

        default:
            cout << "An unknown error occured when calling the game pieces." << endl;
            break;

        }// switch(bitPics)

        return useScreenOutput;

    }// SDL_Surface* ScreenBuild::getGamePieces( SDL_Surface* useScreenOutput )

void ScreenBuild::followSlider()
    {

     SDL_Event sliderMove;
     while(SDL_PollEvent(&sliderMove) != 0)
     {
         if(sliderMove.type == SDL_KEYDOWN)
             {
             if( sliderMove.key.keysym.sym == SDLK_UP )
                 {

                 sliderRectangle.y = sliderRectangle.y - 20;

                 }// if(sliderMove.key.keysym.sym == SDLK_UP)

              if( sliderMove.key.keysym.sym == SDLK_DOWN )
                  {

                  sliderRectangle.y = sliderRectangle.y + 20;

                  }// if( sliderMove.key.keysym.sym == SDLK_DOWN )

              if( sliderRectangle.y <= 0)
                  {

                  sliderRectangle.y = 0;

                  }// if( slideRectangle.y == 0)

              if( sliderRectangle.y >= 358 )
                  {

                  sliderRectangle.y = 358;

                  }// if( sliderRectangle.y == 358 )

             }// if(sliderMove.type == SDL_KEYDOWN)
     }

    }// SDL_Rect* screenBuild::followSlider()

void ScreenBuild::followEnemySlider()
    {

    EnemySliderRectangle.y = ballRectangle.y - 25;

    if( ballCanMoveVertically )
        {

        if( ballRectangle.x + 47 == 567 )
            {

            enemyMissBall = rand() % 10;

            if( enemyMissBall == 5 || enemyMissBall == 6 || enemyMissBall == 7 )
                {

                if( ballVertical = false )
                    {

                    ballRectangle.y = ballRectangle.y + 100;

                    ballRectangle.x = 640;

                    }// if( ballVertical = false )

                else
                    {

                    ballRectangle.y = ballRectangle.y - 100;

                    ballRectangle.x = 640;

                    }// else of if( ballVertical = false )

                }// if( enemyMissBall == 5 )

            else
                {

                EnemySliderRectangle.y = ballRectangle.y - 75;

                }// else of if( enemyMissBall == 5 )

            }// if( ballRectangle.x + 47 == 567 )

        }// if( ballCanMoveVertically )

    }// void ScreenBuild::followEnemySlider()

void ScreenBuild::followBall()
    {

    int verticalAllowed = 0;

    if( ballRectangle.x <= 0 || ballRectangle.x + 47 >= 640 )
        {

        ballRectangle.y = ballY;

        ballRectangle.x = ballX;

        sliderRectangle.y = sliderY;

        EnemySliderRectangle.y = ballRectangle.y - 25;

        ballCanMoveVertically = false;

        ballCanMoveHorizontally = true;

        ballVertical = false;

        ballHorizontal = true;

        }// if( ballRectangle.x == 0 || ballRectangle.x + 47 == 640 )

    if( ballCanMoveVertically )
        {

        if( ballRectangle.y == 0 )
            {

            ballVertical = true;

            }// if( ballRectangle.y == 0 )

        if( ballRectangle.y + 40 == 480 )
            {

            ballVertical = false;

            }// if( ballRectangle.y + 40 == 480 )


        if( ballVertical && ballHorizontal )
            {

            ballRectangle.y = ballRectangle.y + 5;

            ballRectangle.x = ballRectangle.x + 5;

            }// if( ballVertical && ballHorizontal )

        else if( ballVertical && !ballHorizontal )
            {

            ballRectangle.y = ballRectangle.y + 5;

            ballRectangle.x = ballRectangle.x - 5;

            }// else if( ballVertical && !ballHorizontal )

        else if( !ballVertical && ballHorizontal )
            {

            ballRectangle.y = ballRectangle.y - 5;

            ballRectangle.x = ballRectangle.x + 5;

            }// else if( !ballVertical && ballHorizontal )

        else
            {

            ballRectangle.y = ballRectangle.y - 5;

            ballRectangle.x = ballRectangle.x - 5;

            }// else of if( ballVertical && ballHorizontal )

        }// if( ballCanMoveVertically )

        else
            {

            if( ballHorizontal )
                {

                ballRectangle.x = ballRectangle.x + 5;

                }// if( ballHorizontal )

            else
                {

                ballRectangle.x = ballRectangle.x - 5;

                }// else of if( ballHorizontal )

            }// else of if( ballCanMoveVertically )

        // This checks if the ball comes into contact with your slider.

        if( ballRectangle.x <= sliderRectangle.x + 50 )
            {

            if( ballRectangle.y >= sliderRectangle.y && ballRectangle.y <= sliderRectangle.y + 122)
                {

                ballHorizontal = true;

                verticalAllowed = rand() % 10;

                if( verticalAllowed == 1 || verticalAllowed == 5 || verticalAllowed == 8 || verticalAllowed == 9 )
                    {

                    ballCanMoveVertically = true;

                    verticalAllowed = verticalAllowed % 2;

                    if( verticalAllowed == 1 )
                        {

                        ballVertical = true;

                        }// if( verticalAllowed == 1 )

                    else
                        {

                        ballVertical = false;

                        }// else of if( verticalAllowed == 1 )

                    }// if( verticalAllowed == 1 || verticalAllowed == 5 || verticalAllowed == 8 || verticalAllowed == 9 )

                if( verticalAllowed == 3 || verticalAllowed == 7 )
                    {

                    ballCanMoveVertically = false;

                    verticalAllowed = verticalAllowed % 2;

                    if( verticalAllowed == 1 )
                        {

                        ballVertical = true;

                        }// if( verticalAllowed == 1 )

                    else
                        {

                        ballVertical = false;

                        }// else of if( verticalAllowed == 1 )

                    }// if( verticalAllowed == 3 || verticalAllowed == 7 )

                }// if( ballRectangle.x >= sliderRectangle.x && ballRectangle.x <= sliderRectangle.x + 122 )

            }// if( ballRectangle.x == sliderRectangle.x + 50 )

        // this checks if the ball came into contact with the enemy slider.

        if( ballRectangle.x >= EnemySliderRectangle.x - 50 )
            {

            if( ballRectangle.y >= EnemySliderRectangle.y && ballRectangle.y <= EnemySliderRectangle.y + 122 )
                {

                ballHorizontal = false;

                verticalAllowed = rand() % 10;

                if( verticalAllowed == 1 || verticalAllowed == 5 || verticalAllowed == 8 || verticalAllowed == 9 )
                    {

                    ballCanMoveVertically = true;

                    }// if( verticalAllowed == 1 || verticalAllowed == 5 || verticalAllowed == 8 || verticalAllowed == 9 )

                if( verticalAllowed == 3 || verticalAllowed == 7 )
                    {

                    ballCanMoveVertically = false;

                    }// if( verticalAllowed == 3 )

                }// if( ballRectangle.y >= EnemySliderRectangle.y && ballRectangle.y <= EnemySliderRectangle.y + 122 )

            }// if( ballRectangle.x <= EnemySliderRectangle.x )

    }// void screenBuild::followBall()


ScreenBuild::~ScreenBuild()
    {

    }// ScreenBuild::~ScreenBuild()

#endif // PONGIMAGES_H
