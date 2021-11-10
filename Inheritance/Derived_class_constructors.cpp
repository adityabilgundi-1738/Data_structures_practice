#include<iostream>

using namespace std;

class newrecs{
    private:
    char name[20];
    int rollno;
    char subsystem[20];
    int year;

    public:
    void takeinput(){
        cout<<"Enter name"<<endl;
        cin>>name;
        cout<<"Enter rollno"<<endl;
        cin>>rollno;
        cout<<"Enter subsystem Name"<<endl;
        cin>>subsystem;
        cout<<"Enter year"<<endl;
        cin>>year;
    }
    void printer(){
        cout<<"Name : "<<name<<endl;
        cout<<"Rollno : "<<rollno<<endl;
        cout<<"Subsystem Name : "<<subsystem<<endl;
        cout<<"Year : "<<year<<endl;
    }
    
};

class TeamRacing: private newrecs{
    private:
    int goalsReached;
    char currenTasks[20];

    public:
    void takeinput(){
        newrecs::takeinput();
        cout<<"Enter Percentage of annual goals reached"<<endl;
        cin>>goalsReached;
        cout<<"Enter Current Tasks"<<endl;
        cin>>currenTasks;
    }
    void printer(){
        newrecs::printer();
        cout<<"percentage goals Reached"<<goalsReached<<endl;
        cout<<"Current Task"<<currenTasks<<endl;
    }
};

int main(){


    return 0;
}