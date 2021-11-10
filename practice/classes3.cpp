#include <iostream>

using namespace std;

class employee
{
    int id;
    int salary;

public:
    void setid(){
        salary = 122;
        cout << "Enter the id of this employee" << endl;
        cin >> id;
    }
    void getid()
    {
        cout <<"Salary:"<<salary<<endl;
        cout <<"Id"<<id<< endl;
    }
};
int main(){
    employee arr[50];

    for (int i = 0; i < 4; i++)
    {
        cout<<"Employee no "<<i+1<<endl;
        arr[i].setid();
        arr[i].getid();
    }

    return 0;
}