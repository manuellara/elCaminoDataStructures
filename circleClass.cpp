/*

Manuel Lara

Review Question 2

*/

#include <iostream>

using namespace std;

////circle class 
class Circle
{
    private:
        double radius;
        const double pi = 3.14159;

    public:
        /////default constructor
        Circle();
        /////constructor 
        Circle(double rad); 

        ////setter & getters
        void setRadius(double rad)
        {
            radius = rad;
        }
        double getRadius()
        {
            return radius;
        }
        double getArea()
        {
            double area = pi * radius * radius;
            return area;
        }
        double getDiameter()
        {
            double diameter = radius * 2;
            return diameter;
        }
        double getCircumfrence()
        {
            double circumfrence = 2 * pi * radius;
            return circumfrence;
        }
        

};

int main()
{
    ;
}