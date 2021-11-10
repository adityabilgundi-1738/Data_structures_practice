#include<iostream>

using namespace std;
class student{
    int age;
    const int rollno;
    int &j; //age reference var

    public:
    student(int r,int age) : rollno(r),age(age), j(this-> age){ //initialization list

    }
};

int main(){
    
    student a(13,14);


    return 0;
}