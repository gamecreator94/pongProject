#ifndef PONGSCOREKEEPER_H
#define PONGSCOREKEEPER_H
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

/*This class changes the image of the score
and when the image is equal to ten end the game and
determine the winner.*/

class ScoreKeeper
    {

    public:
        ScoreKeeper();
        void setScore();
        void PrintScore();
        bool pongWinner( bool );

    private:
        int scoreCounter;

    };

#endif // PONGSCOREKEEPER_H
