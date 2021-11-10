#include<iostream>

using namespace std;

class onlydynamic{
    private:
    ~onlydynamic(){
        cout<<"Object Destroyed"<<endl;
    }
    public:
    onlydynamic(){
        cout<<"Object created"<<endl;
    }
    friend void destroyer(onlydynamic* bro);
    
};

void destroyer(onlydynamic* bro){
    delete bro;
    cout<<"Destroyed!"<<endl;  
}

int main(){
    //onlydynamic a1; 

    onlydynamic *a2 = new onlydynamic; //syntax for dynamically creating an object
    destroyer(a2);
    return 0;
}