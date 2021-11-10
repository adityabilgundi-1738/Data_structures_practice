#include<iostream>

using namespace std;

class employee{
    float salary;
    float hours;

    public:
    void getinfo(void){
        cout<<"Enter the current salary"<<endl;
        cin>>salary;
        cout<<"Enter the current working hours"<<endl;
        cin>>hours;
    }

    void addsal(void){
        if (salary<=500){
            salary +=10;
        }
    }

    void addwork(void){
        if(hours>=6){
            salary +=5;
        }
    }
    void printsal(void){
        cout<<"Employee working hours: "<<hours<<endl;
        cout<<"Employee salary: "<<salary<<endl;
    }
};

int main(){
    employee a,b;
    cout<<"For employee a"<<endl;
    a.getinfo();
    a.addsal();
    a.addwork();
    a.printsal();
    cout<<"For employee b"<<endl;
    b.getinfo();
    b.addsal();
    b.addwork();
    b.printsal();
    
    return 0;
}