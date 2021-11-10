#include<iostream>

using namespace std;

class calc;
class complex;

int calc :: sumRealComplex(complex o1, complex o2){
    return(o1.a, o2.a);
}

int calc :: sumImagComplex(complex o1, complex o2){
    return(o1.b +o2.b);
}

class calc{
    public:
    int add(int a, int b){
        return(a+b);
    }
    int sumRealComplex(complex o1, complex o2);
    int sumImagComplex(complex o1, complex o2);
};
class complex{
    int a,b;

    //individually decalring functions as friend
    friend int calc ::sumRealComplex(complex o1, complex o2);
    friend int calc ::sumImagComplex(complex o1, complex o2);

    //Aliter: Decalring the entire class as friend

    friend class calc;

    public:
    void setdata(int x, int y){
        a = x;
        b = y;
    }
        
    void getdata(){
        cout<<"The complex number is "<<a<<"+i"<<b<<endl;
    }    
};

//here complex has calc in it & calc has  complex in it
//therefore a mutual forward declaration in the beggining is needed as shown



int main(){


    return 0;
}