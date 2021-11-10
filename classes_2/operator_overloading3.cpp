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

    fraction operator + (fraction const &f2){
        int lcm  = dr*f2.dr;
        int x = lcm /dr;
        int y = lcm /f2.dr;

        int num = x*nr + (y*f2.nr);
        
        fraction f3(num,lcm);

        f3.simplify();

        return f3;
    }

    fraction operator *(fraction f2){
        int num = nr*f2.nr;
        int deno = dr*f2.dr;

        fraction f4(num,deno);

        f4.simplify();
        
        return f4;
    }
    
    bool operator ==(fraction f2){
        return (dr != f2.dr && nr != f2.nr);
    }
    
    fraction& operator ++(){
        nr +=dr;
        simplify();

        return *this;
    }

    fraction operator ++(int){
        fraction fnew(nr,dr);
        nr +=dr;
        simplify();
        fnew.simplify();

        return fnew;

    }

    fraction& operator +=(fraction const &f){
        
        int lcm  = dr*f.dr;
        int x = lcm /dr;
        int y = lcm /f.dr;

        int num = x*nr + (y*f.nr);
        
        nr = num;
        dr = lcm;
        simplify();

        return *this;
    }
};

int main(){
    fraction f1(17,8);
    fraction f2(6,1);

    //f1.printer();
    fraction f6 = f1++;
    // f1.printer();
    // f6.printer();

    fraction f(1,2);
    (f += f2)+=f2;
    f.printer();

    return 0;
}