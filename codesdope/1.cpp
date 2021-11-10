#include<iostream>
#include<string>

using namespace std;

class student{
    public:

    string name;
    int rollno;
};
int main(){
    
    student a;
    a.name = "john";
    a.rollno = 2;

    cout<<"name "<<a.name<<" rollno "<<a.rollno<<endl;
    return 0;
}