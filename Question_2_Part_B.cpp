#include<iostream>
#include<string>
using namespace std;

class Staff{
    public:
        string name;
        int id;
        Staff(string name,int id);
};

Staff::Staff(string name,int id){
    this->name = name;
    this->id = id;
}

class Teacher:public Staff{
    public:
        string subject;
        int qualification;
        Teacher(string sub,int qual,string name,int id);
};
Teacher::Teacher(string sub,int qual,string name,int id):Staff(name,id){
    this->subject = sub;
    this->qualification = qual;
}
class Typist:public Staff{
    public:
        double salary;
};
class Officer:public Staff{
    public:
        string department;
        int grade;
};
class Regular:public Typist{
    public:
        double monthly_salary;
};

class Casual:public Typist{
    public:
        double daily_wage;
};


int main(){

    return 0;
}