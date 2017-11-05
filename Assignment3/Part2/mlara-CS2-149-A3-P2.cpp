/*
    Manuel Lara
    Oct 28 , 2017
    Data Structures 
    Assignment 3::Part 2

    Pseudo code:

    create athlete class
        public: 
            create constructor
            create default constructor 

            create destructor 

            create setters ( first name , last name , salary )
            create getters ( first name , last name , salary )

            create virtual function ( get sal per game )

        protected:
            first name , last name , salary

    create epl class : inherit athlete
        public:
            create constructor : inherit athlete constructor 
            create default constructor : inherit athlete default constructor

            create destructor 

            define virtual function ( get sal per game )

    create nba class : inherit athlete
        public:
            create constructor : inherit athlete constructor 
            create default constructor : inherit athlete default constructor

            create destructor 

            define virtual function ( get sal per game )

    create mlb class : inherit athlete
        public:
            create constructor : inherit athlete constructor 
            create default constructor : inherit athlete default constructor

            create destructor 

            define virtual function ( get sal per game )
    
    create nfl class : inherit athlete
        public:
            create constructor : inherit athlete constructor 
            create default constructor : inherit athlete default constructor

            create destructor 

            define virtual function ( get sal per game )

    main()
    import mlb , nba , epl , nfl

    create mlb object
    create nba object
    create epl object
    create nfl object

    pass objects to their respective functions

    printNBA:
        prints name 
        salary
        pay per game 

    printMLB:
        prints name 
        salary
        pay per game

    printEPL:
        prints name 
        salary
        pay per game

    printNFL:
        prints name 
        salary
        pay per game
*/

#include <iostream>

using namespace std;

#include "mlb.h"
#include "nba.h"
#include "epl.h"
#include "nfl.h"

///////prototypes
void printMLB( mlb x );
void printNBA( nba y );
void printEPL( epl z );
void printNFL( nfl m );

int main()
{
    mlb x( "Clayton" , "Kershaw" , 32000000);
    nba y( "Lebron" , "James" , 30000000 );
    epl z( "Javier" , "Hernandez" , 4000000);
    nfl m( "J.J." , "Watt" , 100000000 );

    //////////passes object to function 
    printMLB( x );
    printNBA( y );
    printEPL( z );
    printNFL( m );
}

////////function definitons 
void printMLB( mlb x )
{
    cout << "MLB" << endl;
    cout << "Player: " << x.getFirstName() << " " << x.getLastName() << endl;
    cout << "Salary: " << x.getSalary() << endl;
    cout << "Pay per game: " << x.salPerGame() << endl << endl; 
}

void printNBA( nba y )
{
    cout << "NBA" << endl;
    cout << "Player: " << y.getFirstName() << " " << y.getLastName() << endl;
    cout << "Salary: " << y.getSalary() << endl;
    cout << "Pay per game: " << y.salPerGame() << endl << endl;
}

void printEPL( epl z )
{
    cout << "EPL" << endl;
    cout << "Player: " << z.getFirstName() << " " << z.getLastName() << endl;
    cout << "Salary: " << z.getSalary() << endl;
    cout << "Pay per game: " << z.salPerGame() << endl << endl; 
}

void printNFL( nfl m )
{
    cout << "NFL" << endl;
    cout << "Player: " << m.getFirstName() << " " << m.getLastName() << endl;
    cout << "Salary: " << m.getSalary() << endl;
    cout << "Pay per game: " << m.salPerGame() << endl << endl; 
}