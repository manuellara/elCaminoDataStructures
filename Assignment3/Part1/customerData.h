#include <iostream>

using namespace std;

#include "personData.h"

class customerData: public personData
{
    public:
        //////////////constructor
        customerData() : personData() 
        { 
            firstName = "mike";
            lastName = "jones";
            address = "123 fake st.";
            city = "Houston";
            state = "TX";
            zip = "505055";
            phoneNumber = "2813308004"; 
        }

        ////////////destructor
        ~customerData(){};

        //////////////setters
        void setCustomerNumbers();
        void setMailingList();

        /////////////getters
        int getCustomerNumbers();
        bool getMailingList();


    protected:
        int customerNumbers;
        bool mailingList; 
};