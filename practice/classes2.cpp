#include<iostream>
#include<string>

using namespace std;

class bank{
    //automatically private
    int balance;
    float interest;
    float taxes;
    float taxp;
    
    //class variables & functions
    static int count;
    static void printer(void){
        cout<<taxes<<endl;
        // the static function can only access the static variables but not any other type of variables
        cout<<count<<endl;
        //works! bcs it is a static variable
    }

    public:
    void printbalance();
    void monthlyInterest();
    void input();
    void tax();
    void taxtarrif();

};
void bank::input(){
    cout<<"Account holder number = "<<count+1<<endl;
    count++;
    cout<<"Enter your monthly balance:"<<endl;
    cin>>balance;
    cout<<"Enter the interest rate:"<<endl;
    cin>>interest;
    cout<<"Tax Tarrif:"<<endl;
    cin>>taxp;
}

int bank::count;
//we can call functions in these functions which are in teh same class
//tax func can call tax tarrif without using the scope resulution operator
void bank::tax(){
    taxes = balance*taxp/100;
    cout<<"for your current back balance, Taxes for this month would be: "<<taxes<<endl;
}
void bank::taxtarrif(){
    cout<<"The current tax Tarrif annouced by the RBI "<<taxp<<endl;
}
void bank::printbalance(){
    cout<<"Your current back balance after tax deductions:"<<balance-taxes<<endl;
}
void bank::monthlyInterest(){
    cout<<"Bank interest for this month: "<<interest<<endl;
}

int main(){
    bank aditya,rohan,rohit;

    aditya.input();
    aditya.tax();
    aditya.printbalance();
    aditya.monthlyInterest();
    aditya.taxtarrif();

    rohan.input();
    rohan.tax();
    rohan.printbalance();
    rohan.monthlyInterest();
    rohan.taxtarrif();

    rohit.input();
    rohit.tax();
    rohit.printbalance();
    rohit.monthlyInterest();
    rohit.taxtarrif();
    

    return 0;
}