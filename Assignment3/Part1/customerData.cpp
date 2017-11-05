#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h> 

using namespace std;

#include "customerData.h"

/////////////setter & getter for customerNumbers
void customerData::setCustomerNumbers()
{
    srand( time(NULL) );
    int customerNumbers = 1 + rand() % 100 ;
}
int customerData::getCustomerNumbers()
{
    return customerNumbers;
}

//////////setter & getter for mailing  list
void customerData::setMailingList()
{
    srand( time(NULL) );    
    int mailingList = rand() % 2 ;
}
bool customerData::getMailingList()
{
    if( mailingList == 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}


