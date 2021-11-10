#include<iostream>

using namespace std;
class student{
    int rollno;
    int age;

    // static int totalstudents; //tot students present, use the function to access
    public:
    static int totalstudents ; //tot students present, use scope resolution to access
    
    student(int rollno, int age){
        this -> rollno = rollno;
        this -> age = age;
        totalstudents++; //implementing this here bcs,
        //constructor is called everytime an object is initialised 
    }
    
    void printer(){
        cout<<rollno<<" "<<age;
    }
    // int getTotalStudents(){ //wont work
    //     return totalstudents;
    // }
    static int getTotalStudents(){ //works
        return totalstudents; //for static objects, only static functions work on them
    }
};

int student :: totalstudents = 0; //declaring its value

int main(){

    student s1(23,30);
    student s2(23,30);
    student s3(23,30);
    student s4(23,30);

    cout<<student::totalstudents<<endl;
    // cout<<getTotalStudents()<<endl; //doesnt work
    cout<<student::getTotalStudents()<<endl;
    return 0;
}