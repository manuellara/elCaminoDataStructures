/*

Manuel Lara

Review question 1

*/


#include <iostream>
#include <iomanip>

///////function prototype
void calcAmountSpentForTheYear( double totalAmount[] , int sizeOfArray );
void calcAverageMonthlySpent( double totalAmount[] , int sizeOfArray );
void findHighestCharge( double totalAmount[] , int sizeOfArray );
void findLowestCharge( double totalAmount[] , int sizeOfArray );

using namespace std;

int main()
{
    double totalAmount[12];
    double monthlyAmount;

    /////fills array with 12 charges
    for (int i = 0; i < 12 ; i++)
    {
        cout << "Enter amount spent for month " << i + 1 << ": ";
        cin >> monthlyAmount;

        if (monthlyAmount < 0)
        {
            cout << "Error: amount less than 0; value for month "<< i + 1 <<" will be 0"<< endl;
            monthlyAmount = 0;
        }

        totalAmount[i] = monthlyAmount;
    }

    /////claculates amount spent for the year
    calcAmountSpentForTheYear( totalAmount , 12 );

    /////calculates average amonthly spent
    calcAverageMonthlySpent( totalAmount , 12 );

    ////claculates highest
    findHighestCharge( totalAmount , 12 );

    ////calculate lowest 
    findLowestCharge( totalAmount , 12 );
    
}

void calcAmountSpentForTheYear( double totalAmount[] , int sizeOfArray )
{
    double total;

    for (int i = 0 ; i < sizeOfArray ; i++)
    {
        total += totalAmount[i];
    }

    cout << left << setprecision(2) << showpoint;
    cout << "Total amount spent for the year: " << total << endl;
}

void calcAverageMonthlySpent( double totalAmount[] , int sizeOfArray )
{
    double total;

    for (int i = 0 ; i < sizeOfArray ; i++)
    {
        total += totalAmount[i];
    }

    total = total / 12;

    cout << left << setprecision(2) << showpoint;
    cout << "Average monthly spent: " << total << endl;
}

void findHighestCharge( double totalAmount[] , int sizeOfArray )
{
    double highest = -1;
    int index;

    for (int i = 0 ; i < sizeOfArray ; i++)
    {
        if ( totalAmount[i] > highest )
        {
            highest = totalAmount[i];
            index = i + 1;
        }
    }

    cout << left << setprecision(2) << showpoint;
    cout << "Month " << index << " had the highest amount spent at " << highest << endl;
}

void findLowestCharge( double totalAmount[] , int sizeOfArray )
{
    double lowest = -1 ;
    int index;

    for (int i = 0 ; i < sizeOfArray ; i++)
    {
        if (lowest == -1)
        {
            lowest = totalAmount[i];
            index = i;
        }
        else if (totalAmount[i] < lowest)
        {
            lowest = totalAmount[i];
            index = i;
        }
    }

    cout << left << setprecision(2) << showpoint;
    cout << "Month " << index + 1 << " had the lowest amount spent at " << lowest << endl;
}