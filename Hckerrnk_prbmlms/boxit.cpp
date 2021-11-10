#include<iostream>

using namespace std;

class Box{
    private:
    int l,b,h;

    public:
    Box(){ //default constructor with default args
        l = 0; b = 0; h = 0;
    }; 
    Box(int x, int y ,int z){
        l = x; b = y; h = z;
    }
    Box(const Box &B){ //copy const
        l = B.l; b = B.b; h = B.h;
    }
    int getLength();
    int getBreadth ();
    int getHeight ();
    long long CalculateVolume();
    
    bool operator < (Box d){
        bool a  = false;
        if(l < d.l){
            a = true;
        }
        if((b < d.b) && (l == d.l)){
            a+= true;
        }
        if((h < d.h) && (l == d.l) && (b == d.b)){
            a+=true;
        }
        return a;
    }
    friend ostream& operator<< (ostream& os, const Box& e);

};

ostream& operator<< (ostream& os, const Box& e){
        os<<e.l<<" "<<e.b<<" "<<e.h;
        return os;
}
int Box :: getBreadth(){
    return b;
}
int Box :: getLength(){
    return l;
}
int Box :: getHeight(){
    return h;
}
long long Box ::CalculateVolume(){
    return l*b*h;
}

int main(){
    Box b1,b2;
    bool op = (b1 <b2);
    cout << b1;

    return 0;
}