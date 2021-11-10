#include<iostream>

using namespace std;


class complex{
    int a,b;
    public:
    complex(int x ,int y){ //constructor with 2 args
        a = x;
        b = y;
    }
    complex(int x){ //constructor with 1 args
        a = x;
        b = 7;
    }
    complex(){ //constructor with 0 args
        a = 8;
        b = 8;
    }
    // this is called constructor overloading

    void printpoint(){
        cout<<"the point: "<<a<<" + i"<<b<<endl;
    }
}; 

int main(){
    complex a(5);
    a.printpoint();

    complex b(7,8);
    b.printpoint();

    complex c;
    c.printpoint();

    return 0;
}