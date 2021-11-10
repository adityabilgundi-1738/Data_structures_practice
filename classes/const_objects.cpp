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

    const void printer(){
        cout<<nr<<"/"<<dr<<endl;
    }
    
    int getnumerc() const{
        return nr;
    }
    int getnumer() {
        return nr;
    }

    int getdenoc() const{
        return dr;

    }
    int getdeno(){
        return dr;

    }

    void setdeno(int a){
        dr = a;
    }
    void setnum(int b){
        nr = b;
    }

    void simp(){
        int gcd = 1;
        int j = min(this->nr,this->dr);
        for (int i = 1; i <= j; i++){ 
            if((this->nr%i==0) && (this->dr%i==0))
                gcd = i;
        }

        this->nr /=gcd;
        this->dr /=gcd;
    }
    
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
    fraction f1(10,2);
    fraction f2(15,4);

    fraction const f3;
    
    // cout<<f3.getnumer()<<" "<<f3.getdeno()<<endl;

    // as f3 is a constant obj, we cant call any normal functions
    // but we are allowed to call constant functions
    cout<<f3.getnumerc()<<" "<<f3.getdenoc()<<endl;
    


    return 0;
}