#include <iostream>

using namespace std;

#include "athlete.h"

class mlb : public athlete
{
    public:
        //////////////constructor
        mlb( string fn , string ln , double sal ) : athlete( fn  , ln  , sal  )
        {
            firstName = fn;
            lastName = ln;
            salary = sal;
        }
        mlb() : athlete()
        {
            firstName = "mike";
            lastName = "jones";
            salary = 0;
        }

        //////////////destructor
        ~mlb(){};

        /////////////salary per game calculator
        double salPerGame();


};