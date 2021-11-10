#include<iostream>

using namespace std;
class y;
class x;
void exchange(x &a,y &b);


class x{
    int num1;
    public:
    void display(){
        cout<<num1<<endl;
    }
    void input(int num){
        num1 = num;
    }
    friend class y;
    friend void exchange(x &a,y &b);
};

class y{
    int num1;
    public:
    void display(){
        cout<<num1<<endl;
    }
    void input(int num){
        num1 = num;
    }
    friend void exchange(x &a,y &b);
};

void exchange(x &a,y &b){
    int temp = a.num1;
    a.num1 = b.num1;
    b.num1 = temp;
}

int main(){
    x a1;
    y b1;

    a1.input(16);
    b1.input(20);
    cout<<"Values of a1 & b1 before swap:"<<endl;
    cout<<"a = ";
    a1.display();
    cout<<"b = ";
    b1.display();

    cout<<"Values of a1 & b1 after swap:"<<endl;
    exchange(a1,b1);
    cout<<"a = ";
    a1.display();
    cout<<"b = ";
    b1.display();

    return 0;

    
}
