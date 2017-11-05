#include <iostream>

using namespace std;

#include "athlete.h"

class epl : public athlete
{
    public:
        //////////////constructor
        epl( string fn , string ln , double sal ) : athlete( fn  , ln  , sal  )
        {
            firstName = fn;
            lastName = ln;
            salary = sal;
        }
        epl() : athlete()
        {
            firstName = "mike";
            lastName = "jones";
            salary = 0;
        }

        //////////////destructor
        ~epl(){};

        /////////////salary per game calculator
        double salPerGame();

};