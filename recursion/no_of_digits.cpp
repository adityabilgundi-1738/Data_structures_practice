#include<iostream>

using namespace std;

int digits(int n){
    if(n == 0){
        return 0;
    }
    return 1 + digits(n/10);
}   

int main(){
    cout<<"Enter n"<<endl;
    int number;
    cin>>number;
    cout<<endl;
    cout<<digits(number)<<endl;


    return 0;
}