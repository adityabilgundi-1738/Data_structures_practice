#include<iostream>

using namespace std;

class classy{
    int x,y;

    public: 
    classy(int a,int b = 9){ //note default arguments should be at the end of the argument list only
    //i.e, classy(int b = 9, int a) throws an error
        x = a;
        y = b;
    }
    
    void printpoint(){
        cout<<"the point: "<<x<<" + i"<<y<<endl;
    }

};
int main(){

    classy c(4,8);
    c.printpoint();
    //output here would be 4 +8i 
    //meaning it overwrites the defaults
    classy b(8);
    //output here would be 8 +9i 
    //meaning it fills only the FIRST one
    //because of that rule on line 9
    b.printpoint();
    
    return 0;
}