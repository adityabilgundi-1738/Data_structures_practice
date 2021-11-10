#include<iostream>

using namespace std;

class student{
    public:
    int roll;
    int age;
    void printer(){
        cout<<roll<<" "<<age;
    }
};

int main(){
    student s1;
    s1.roll = 24;
    s1.age = 15;

    student *s2 = new student;
    //s2.age = 24; //wrong
    s2->age = 15; //correct
    (*s2).age = 26; //correct
    //similar for functions
    s2->printer(); //correct




    return 0;
}