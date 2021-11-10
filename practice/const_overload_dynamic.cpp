#include<iostream>

using namespace std;

class deposit{
    int principal;
    int years;
    float rate;
    float amount;

    public:
    deposit(int p, int y, int r);

    deposit(int p,int y, float r);

    deposit(){} //default constructor or Blank constructor

    void printer();
};

deposit ::deposit(int p,int y, float r){
    principal = p;
    years = y;
    rate = r;
    amount = principal;

    for (int i = 0; i < y; i++){
        amount = amount*(1+rate);
    }
}

deposit ::deposit(int p, int y, int r){
    principal = p;
    years = y;
    rate = float(r)/100;
    amount = principal;
        
    for (int i = 0; i < y; i++){
        amount = amount*(1+rate);
    }
}

void deposit :: printer(){
    cout<<"Amount after Compund interest: "<<amount<<endl;
}

int main(){
    deposit p1 ,p2 ,p3;
    int p,r,y;
    float R;

    cout<<"enter the values"<<endl;
    cin>>p>>r>>y;
    p1 = deposit(p,y,r);
    p1.printer();

    cout<<"enter the values"<<endl;
    cin>>p>>R>>y;
    p2 = deposit(p,y,R);
    p2.printer();

    return 0;
}