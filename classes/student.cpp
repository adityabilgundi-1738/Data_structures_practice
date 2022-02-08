#include<iostream>
#include<string.h>

using namespace std;

class student{
    int age;
    public:
    char *name;
    
    student(int age, char *name){
        this -> age = age;
        //this -> name = name; //shallow copy
        
        //deep copy
        this -> name = new char[strlen(name) + 1];
        strcpy(this->name ,name);
    }
    student(student const &s){
        this->age = s.age;
        //this->name= s.name; //shallow copy

        //deep copy
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this->name ,s.name);
    }
    
    void printer(){
        cout<<"Age: "<<age<<" and Name: "<<name<<endl;
    }
};

int main(){
    
    char name[] = "aditya";
    student a(1,name);
    a.printer();
    
    student b(a);
    
    b.name[0] = 'x';
    a.printer();
    b.printer();


    return 0;
}