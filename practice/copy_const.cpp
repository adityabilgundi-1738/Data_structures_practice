#include<iostream>

using namespace std;

class number{
    int x;

    public:
    number(){x = 0;}

    number(int a){
        x = a;
    }

    number(number &obj){ //custom copy constructor
        x = obj.x;
    }
    //even if we didnt create this copy constructor, the compiler would create one on its own
    //the same  syntax is applied

    // if we dont make a custom copy constructor, the compiler makes its own copy constructor

    void display(){
        cout<<"The number for this object is"<<x<<endl;
    }

};

int main(){
    number p ,q ,r(30);

    p.display();
    q.display();
    r.display();

    number z1(p); //copy constructor 
    z1.display();

    number z2 = q; //same (works)
    z2.display();

    number z3(r);
    z3.display();

    return 0;
}