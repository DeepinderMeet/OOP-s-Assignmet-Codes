#include <iostream>
#include <string>
using namespace std;

class Staff
{
public:
    string name;
    int id;
    Staff(string name, int id);
};

// CONSTRUCTOR OF THE STAFF CLASS
Staff::Staff(string name, int id)
{
    this->name = name;
    this->id = id;
}

class Teacher : public Staff
{
public:
    string subject;
    string qualification;
    void show();
    Teacher(string name, int id, string sub, string qual);
};
// show of the Teacher Class
void Teacher::show(){
    cout<<"Deatils of the Teacher"<<endl;
    cout<<"Name: " <<name<<endl;
    cout<<"ID: " <<id<<endl;
    cout<<"Subject: " <<subject<<endl;
    cout<<"Qualification: " <<qualification<<endl;
}

// CONSTRUCTOR OF THE TEACHER CLASS
Teacher::Teacher(string name, int id, string sub, string qual) : Staff(name, id)
{
    this->subject = sub;
    this->qualification = qual;
}

class Typist : public Staff
{
public:
    // double salary;
    Typist(string name, int id);
};
// CONSTRUCTOR OF THE TYPIST CLASS
Typist::Typist(string name, int id) : Staff(name, id)
{
    // this->salary = sal;
}

class Officer : public Staff
{
public:
    string department;
    void show();
    Officer(string name, int id, string dept);
};
// show of the Officer Class
void Officer::show(){
    cout<<"Deatils of the Officer"<<endl;
    cout<<"Name: " <<name<<endl;
    cout<<"ID: " <<id<<endl;
    cout<<"Department: " <<department<<endl;
}

// CONSTRUCTOR OF THE OFFICER CLASS
Officer::Officer(string name, int id, string dept) : Staff(name, id)
{
    this->department = dept;
}

class Regular : public Typist
{
public:
    double monthly_salary;
    void show();
    Regular(string name, int id, double sal);
};
// show of the Regular Typist Class
void Regular::show(){
    cout<<"Deatils of the Regular Typist"<<endl;
    cout<<"Name: " <<name<<endl;
    cout<<"ID: " <<id<<endl;
    cout<<"Salary: " <<monthly_salary<<endl;
}
// CONSTRUCTOR OF THE REGULAR TYPIST CLASS
Regular::Regular(string name, int id, double sal) : Typist(name, id)
{
    this->monthly_salary = sal;
}

class Casual : public Typist
{
public:
    double daily_wage;
    Casual(string name, int id, double sal);
    void show();
};
// show of the Casual Typist Class
void Casual::show(){
    cout<<"Deatils of the Casual Typist"<<endl;
    cout<<"Name: " <<name<<endl;
    cout<<"ID: " <<id<<endl;
    cout<<"Salary: " <<daily_wage<<endl;
}
// CONSTRUCTOR OF THE CASUAL TYPIST CLASS
Casual::Casual(string name, int id, double sal) : Typist(name, id)
{
    this->daily_wage = sal;
}

int main()
{
    Teacher t1("Gagan",66,"EDG","M.Tech");
    Officer o1("Deepinder",67,"IT block");
    Regular r1 ("John",55,12450.00);
    Casual c1 ("Uday",56,1456.00);

    // Displaying all the THINGS
    t1.show();
    o1.show();
    r1.show();
    c1.show();

    return 0;
}