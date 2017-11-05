#include <iostream>

using namespace std;

#include "athlete.h"

class nba : public athlete
{
    public:
        //////////////constructor
        nba( string fn , string ln , double sal ) : athlete( fn  , ln  , sal  )
        {
            firstName = fn;
            lastName = ln;
            salary = sal;
        }
        nba() : athlete()
        {
            firstName = "mike";
            lastName = "jones";
            salary = 0;
        }

        //////////////destructor
        ~nba(){};

        /////////////salary per game calculator
        double salPerGame();

};