#include <iostream>

using namespace std;

#include "athlete.h"

class nfl : public athlete
{
    public:
        //////////////constructor
        nfl( string fn , string ln , double sal ) : athlete( fn  , ln  , sal  )
        {
            firstName = fn;
            lastName = ln;
            salary = sal;
        }
        nfl() : athlete()
        {
            firstName = "mike";
            lastName = "jones";
            salary = 0;
        }

        //////////////destructor
        ~nfl(){};

        /////////////salary per game calculator
        double salPerGame();

};