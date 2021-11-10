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
    pair < pair<int,int> , bool > p1;//we will get class with int,bool elements
    pair <int,int> p2;
    
    p1.Sety(0);

    p2.Setx(17);
    p2.Sety(38);

    p1.Setx(p2);

    std::cout<<p1.getX().getX()<<std::endl<<p1.getX().getY()<<std::endl;
    std::cout<<p1.getY()<<std::endl;

    return 0;
}