#include <iostream>
#include <string>
using namespace std;

/// 100 -> 60
/// 200 -> 80
/// 300 -> 90

class charges
{
private:
    string name;
    int units, amount;
    float charge = 0;

public:
    charges(string name, int units);
    void amount_to_be_paid();
    void display_info();
};

// constructor
charges::charges(string name, int units)
{
    this->name = name;
    this->units = units;
}

// function to calculate the charges
void charges::amount_to_be_paid()
{
    // if less than 50 return 50
    // float charge = 0;
    if (units >= 0 && units <= 100)
    {
        charge = units * 0.60;
        cout << "First 100 units " << charge << endl;
    }
    else if (units <= 300)
    {
        charge = (100 * 0.60); // calculated the bill for the first hundred units
        units = units - 100;
        charge = charge + (units * 0.80);
    }
    else if (units > 300)
    {
        charge = (100 * 0.60);          // calculated the bill for the first hundred units
        charge = charge + (200 * 0.80); // calculated the bill for the 200 units hundred units
        units = units - 300;
        charge = charge + (units * 0.90); // calculated the bill for the units above 300
    }
    if (charge < 50)
    {
        charge = 50;
    }
    else if (charge > 300)
    { // if bill > 300 then 15% as Per NIRMALA SITARAMAN
        charge = charge + (charge * 0.15);
    }
}

// function to display the name and the charges
void charges::display_info()
{
    cout << "Name: " << name << endl;
    cout << "Charges: " << charge << endl;
}
int main()
{
    charges c1("Gagan", 400);
    c1.amount_to_be_paid();
    c1.display_info();
    return 0;
}