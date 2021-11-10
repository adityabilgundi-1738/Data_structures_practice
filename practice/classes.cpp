#include<iostream>
#include<string>

using namespace std;
class human{
    public:
    
    string name;
    void printname(){
        cout<<"His name is "<<name<<endl;
        //defined function inside the class
    }
    
    void grandbro();
    //defined function outside the class but declaration must be present in this
};
void human::grandbro(){
    cout<<"piro gamer"<<endl;
}

int main(){
    human a;
    a.name = "Aditya";
    a.printname();
    a.grandbro();
    return 0;
}

