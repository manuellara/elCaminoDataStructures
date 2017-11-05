#ifndef _athlete         ///guards - if not defined : define
#define _athlete


#include <iostream>

using namespace std;

class athlete
{
    public:
        ///////////constructors
        athlete( string , string , double );
        athlete();

        /////////destructor
        ~athlete();

        //////////setters
        void setFirstName( string );
        void setLastName( string );
        void setSalary( double );

        //////////getters
        string getFirstName();
        string getLastName();
        double getSalary();  

        //////////virtual function
        virtual double salPerGame();

    protected: 
        string firstName;
        string lastName;
        double salary;
};



#endif                   /////end guards