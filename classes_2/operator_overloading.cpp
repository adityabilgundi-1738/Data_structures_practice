#include<iostream>

using namespace std;
//making changes to the fraction class
class fraction{
    int nr;
    int dr;
    
    public:
    fraction(){nr = 1; dr = 1;};
    fraction(int a, int b){
        nr = a;
        dr = b;
    }

    void printer(){
        cout<<nr<<"/"<<dr<<endl;
    }
    
    void simplify(){
        int gcd = 1;
        int j = min(this->nr,this->dr);
        for (int i = 1; i <= j; i++){ 
            if((this->nr%i==0) && (this->dr%i==0))
                gcd = i;
        }
        this->nr /=gcd;
        this->dr /=gcd;
    }

    fraction operator +(fraction const &f2){//overloaded addition
        int lcm  = dr*f2.dr;
        int x = lcm /dr;
        int y = lcm /f2.dr;

        int num = x*nr + (y*f2.nr);
        
        fraction f3(num,lcm);

        f3.simplify();

        return f3;
    }

    fraction operator *(fraction const &f2){//overloaded multiplication
        //we can optimise it by using const & thingy
        int num = nr*f2.nr;
        int deno = dr*f2.dr;

        fraction f4(num,deno);

        f4.simplify();
        
        return f4;
    }
    
    fraction operator -(fraction const &f2){
        int num = nr*f2.dr - f2.nr*dr;
        int den = dr*f2.dr;

        fraction f3(num,den);

        f3.simplify();

        return f3;
    }

    bool operator ==(fraction f2){ //we can optimise it by using const & thingy
        return (dr != f2.dr && nr != f2.nr);
    }
};

int main(){
    fraction f1(12,1);
    fraction f2(12,1);

    fraction f3 = f1+f2;
    cout<<"Sum:"<<endl;
    f3.printer();

    fraction f4 = f1*f2;
    cout<<"Product"<<endl;
    f4.printer();

    fraction f5 = f1-f2;
    cout<<"Difference"<<endl;
    f5.printer();

    // if(f1 == f2){
    //     cout<<"Both are equal"<<endl;
    // }
    // else{
    //     cout<<"Both are not equal"<<endl;
    // }
    return 0;
}