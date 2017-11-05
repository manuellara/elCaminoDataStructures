#include <iostream>

using namespace std;

#include "athlete.h"

/////////constructors
athlete::athlete( string fn , string ln , double sal )
{
    firstName = fn;
    lastName = ln;
    salary = sal;
}
athlete::athlete()
{
    firstName = "mike";
    lastName = "jones";
    salary = 0;
};

////////destructor 
athlete::~athlete(){};

/////////////////setters
void athlete::setFirstName( string firstName )
{
    firstName = firstName;
}
void athlete::setLastName( string lastName )
{
    lastName = lastName;
}
void athlete::setSalary( double salary )
{
    salary = salary;
}

//////////////////getters
string athlete::getFirstName()
{
    return firstName;
}
string athlete::getLastName()
{
    return lastName;
}
double athlete::getSalary()
{
    return salary;
}

/////////////////virtual function
double athlete::salPerGame()
{
    return salary/0;
}