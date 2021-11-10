#include<iostream>

using namespace std;

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
    
    void simp(){
        int gcd = 1;
        int j = min(this->nr,this->dr);
        for (int i = 1; i <= j; i++){ //here the iterator starts from 1 lol
            if((this->nr%i==0) && (this->dr%i==0))
                gcd = i;
        }

        this->nr /=gcd;
        this->dr /=gcd;
    }
    
    //void adder(fraction f2){ //here  fraction f2 calls the copy constructor there fore taking more space than needed
    //calling the address of the argument is more efficient
    //taking &f2 gives another problem, a person could easily access the variables
    //therefore using const &f2 is the solution
    void adder(fraction const &f2){
        int lcm  = dr*f2.dr;
        int x = lcm /dr;
        int y = lcm /f2.dr;

        int num = x*nr + (y*f2.nr);
        nr = num;
        dr = lcm;
        simp();
    }
};

int main(){
    fraction f1(12,17);
    fraction f2(13,1);

    f1.adder(f2);
    f1.printer();
    f2.printer();
    
    return 0;
}