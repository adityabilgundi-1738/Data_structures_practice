#include<iostream>

using namespace std;
class student{
    int a,b;
    public:

    void printer(){
        cout<<a<<" "<<b<<endl;
    }
    student(){a = 0; b = 13;}; //default constrcutor with default args
    //student(){}; //default constrcutor with no default args

    student(int x){
        a = x;
    }
    student(int x, int y){
        a = x;
        b = y;
    }
    // custom copy constructor
    student(student const &brr){
        a = brr.b;
        b = brr.a;
    }
    
    //the copy constructor made by the compiler itself does this 
    //  student(student &brr){
    //     a = brr.a;
    //     b = brr.b;
    // }
};

int main(){
    student hello(12,14);
    hello.printer();
    student hello1;
    hello1.printer();
    student hello2(1200);
    hello2.printer();
    student hello3(hello1);
    hello3.printer();


    return 0;
}
