#include<iostream>
#include<string>

using namespace std;

class student{
    public:
    string address;
    string phoneno;
    int rollno;


};

int main(){

    student john,sam;

    john.rollno  =12;
    john.address = "no12, brrr, brrrrrr, bangalore";
    john.phoneno = "1234567890";

    sam.rollno = 13;
    sam.phoneno = "123123123";
    sam.address = "no13, vrrom ,vrrrooom, hublu";

    cout<<"Sam"<<endl;
    cout<<"Address "<<sam.address<<endl;
    cout<<"rollno "<<sam.rollno<<endl;
    cout<<"phone no "<<sam.phoneno<<endl;

    cout<<"John"<<endl;
    cout<<"Address "<<john.address<<endl;
    cout<<"rollno "<<john.rollno<<endl;
    cout<<"phone no "<<john.phoneno<<endl;


    return 0;
}