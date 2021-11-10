#include<iostream>

template <typename T>

class pair{
    T x,y;
    public:
    void Setx(T x){
        this->x = x;
    }
    void Sety(T y){
        this->y = y;
    }

    T getX(){
        return x;
    }
    T getY(){
        return y;
    }
};

int main(){
    pair <int> p1;//we will get class with int elements
    pair <double> p2;//we will get class with double elements
    pair <char> p3;
    p1.Setx(10);
    p1.Sety(20);

    std::cout<<p1.getX()<<std::endl<<p1.getY()<<std::endl;

    p2.Setx(16.34);
    p2.Sety(16.35);

    std::cout<<p2.getX()<<std::endl<<p2.getY()<<std::endl;
    return 0;
}



