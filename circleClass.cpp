/*

Manuel Lara

Review Question 2

*/
#include <iostream>

using namespace std;

const double pi = 3.14159;

////circle class 
class Circle
{
    private:
        double radius;

    public:
        /////default constructor
        Circle();
        /////constructor 
        Circle(double rad); 

        ////set & get functions
        void setRadius(double rad);
        void getRadius();
        double getArea();
        double getDiameter();
        double getCircumfrence();
        

};

int main()
{
    ;
}