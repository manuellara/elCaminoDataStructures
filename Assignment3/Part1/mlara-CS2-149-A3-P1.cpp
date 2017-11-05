/*

    Manuel Lara
    Oct 28 , 2017
    Data Structures 
    Assignment 3::Part 1

    Pseudo code:

    create person class 
        public:
            create constructor 
            create default constructor 

            create destructor 

            create setters for person ( first name , last name , city , etc... )
            create getters for person ( first name , last name , city , etc... )

        protected:
            first name , last name , address , city , state , zip , phone number


    create customer class : inherit person
        public: 
            create default constructor : inherit person default constructor 

            create destructor 

            create setters for customer ( number , mailing list )

            create getters for customer ( number , mailing list )

        protected: 
            numbers , mailing list


    main()
    include customerData.h 

    create random number 

    create customer pointer array with size of random number

    create for loop to iterate pointer array
        set customerNumbers
        set mailingList

        if mailingList == true:
            print statement with customers approval
            else
            print statement with customers disapproval 
        
*/


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h> 

using namespace std;

#include "customerData.h"

int main()
{
    /////////x = random number between 0-2
    srand( time(NULL) );
    int x = 1 + rand() % 20;

    ////////creates x amount of pointer objects 
    customerData* y ;
    y = new customerData[x];
    
    ////////iterates through array 
    for(int i = 0 ; i < x ; i++)
    {
        (y + i)->setCustomerNumbers();
        (y + i)->setMailingList();

        if( (y + i)->getMailingList() == true )
        {
            cout << i << ". " << (y + i)->getFirstName() << " " <<(y + i)->getLastName() << " wishes to be on the mailing list." << endl;
        }
        else
        {
            cout << i << ". " << (y + i)->getFirstName() << " " << (y + i)->getLastName() << " does NOT want to be on the mailing list." << endl;
        }
    }

}