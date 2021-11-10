#include<iostream>

using namespace std;

class complex{
    int a;
    int b;
    public:
    void setdata(int x, int y){
        a = x;
        b = y;
    }
    void getdata(){
        cout<<"The complex number is "<<a<<"+i"<<b<<endl;
    }
    void setdatasum(complex r,complex i){
        a = r.a +r.b;
        b = i.a +i.b;
    }
    //this might feel similar to structures but in structs we used to declare values directly 
    //but in classes we need to use functions to access elements
    //directly assigning varibles isnt allowed
};
int main(){
    complex c1,c2,c3;
    c1.setdata(2,5);
    c1.getdata();

    c2.setdata(5,8);
    c2.getdata();

    c3.setdatasum(c1,c2);
    c3.getdata();
    
    return 0;
}