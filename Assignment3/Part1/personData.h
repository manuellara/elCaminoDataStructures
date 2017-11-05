#ifndef _personData
#define _personData


#include <iostream>

using namespace std;

class personData
{
    public:
        ///////////constructors
        personData( string fn , string ln , string ad , string cit , string st , string z , string pn )
        {
            firstName = fn;
            lastName = ln;
            address = ad;
            city = cit;
            state = st;
            zip = z;
            phoneNumber = pn;
        }
        personData()
        {
            firstName = "";
            lastName = "";
            address = "";
            city = "";
            state = "";
            zip = "";
            phoneNumber = "";
        }

        ///////////destructor 
        ~personData(){};

        ///////////setters
        void setFirstName( string firstName );
        void setLastName( string lastName );
        void setAddress( string address );
        void setCity( string city );
        void setState( string state );
        void setZip( string zip );
        void setPhoneNumber( string phoneNumber );

        //////////getters
        string getFirstName();
        string getLastName();
        string getAddress();
        string getCity();
        string getState();
        string getZip();
        string getPhoneNumber();

    protected:
        string firstName , lastName , address , city , state , zip , phoneNumber; 
        
};


#endif