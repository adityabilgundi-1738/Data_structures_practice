#include<iostream>

using namespace std;

class student{
    private:
    int roll;
    string firstname;
    string secondname;
    int std;

    public:

    void inroll(void){
        cin>>roll;
    }

    void infirst(void){
        cin>>firstname;
    }

    void insecond(void){
        cin>>secondname;
    }
    void instd(void){
        cin>>std;
    }

    void printer(void){
        cout<<roll<<endl;
        cout<<secondname<<", "<<firstname<<endl;
        cout<<std<<endl;
        cout<<endl;
        cout<<roll<<","<<firstname<<","<<secondname<<","<<std;
    }
};

int main(){
    student a;

    a.inroll();
    a.infirst();
    a.insecond();
    a.instd();
    a.printer();
    return 0;
}