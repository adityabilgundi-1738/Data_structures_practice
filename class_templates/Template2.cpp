#include<iostream>

template <typename T,typename V>

class pair{//multi custom ele class
    T x;
    V y;
    public:
    void Setx(T x){
        this->x = x;
    }
    void Sety(V y){
        this->y = y;
    }

    T getX(){
        return x;
    }
    V getY(){
        return y;
    }
};

int main(){
    pair <int,bool> p1;//we will get class with int,bool elements
    pair <double,int> p2;//we will get class with double,int elements
    pair <char,bool> p3;
    
    p1.Setx(10);
    p1.Sety(1);

    std::cout<<p1.getX()<<std::endl<<p1.getY()<<std::endl;

    p2.Setx(16.34);
    p2.Sety(173);

    std::cout<<p2.getX()<<std::endl<<p2.getY()<<std::endl;
    

    p3.Setx('a');
    p3.Sety(0);

    std::cout<<p3.getX()<<std::endl<<p3.getY()<<std::endl;
    return 0;
}



