#include <iostream>
#include <string>
using namespace std;

class B;
class A
{
private:
    float meters;
    // we will enter the distance in meters and will convert it to centimeters
    float centimeters;

public:
    A(float meters, float centimeters)
    {
        this->meters = meters;
        this->centimeters = centimeters;
    }
    friend void added_distance(const A &a1, const B &b1);
};

class B
{
private:
    float feet;
    // we will enter the distance in feets and will convert it to inches
    float inches;

public:
    B(float feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;
    }
    friend void added_distance(const A &a1, const B &b1);
};

// we define the friend functions normally outside the class without any scope resolution operator
void added_distance(const A &a1, const B &b1)
{

    // Firstly add the distances of class A
    float added_in_meters = a1.meters + (a1.centimeters / 100);
    // now add the distances of class B
    float added_in_inches = b1.feet * 12 + b1.inches;
    // now convert the added distance of the Class B to meters; //////1 inch = 0.0254 meters
    float in_meters = added_in_meters + (added_in_inches * 0.0254);
    // the above is the added distance of the two classes which is in meters

    int total_meters = in_meters;
    float total_centimeters = (in_meters - total_meters) * 100;
    // ( in_meters - total_meters)  <- this gives the decimal part

    // now to display it
    cout << "The distance in Meters is " << total_meters << endl;
    cout << "The distance in Centimeters is " << total_centimeters << endl;
}

int main()
{
    A a1(2, 75); // 2 meters 75 cm
    B b1(6, 3);  // 6 feet 3 inches

    added_distance(a1, b1);

    return 0;
}