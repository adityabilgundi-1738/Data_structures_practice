#include<iostream>

using namespace std;

class complex{
    int a,b;
    public:
        void setdata(int x, int y){
            a = x;
            b = y;
        }
        friend complex sumcomplex(complex o1, complex o2);
        void getdata(){
            cout<<"The complex number is "<<a<<"+i"<<b<<endl;
        }
        
};
//friend functions are not in the scope of the class

complex sumcomplex(complex o1, complex o2){
    complex o3;
    o3.setdata((o2.a +o1.a),(o2.b +o1.b));
    return o3;
};

int main(){
    complex c1,c2;
    c1.setdata(2,5);
    c2.setdata(4,5);
    complex c3 = sumcomplex(c1,c2);
    c3.getdata();

    return 0;
}
