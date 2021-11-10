#include<iostream>

using namespace std;

int fibo(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int smalloutput1 = fibo(n-1);
    int smalloutput2 = fibo(n-2);
    return smalloutput1 + smalloutput2;
}

int main(){
    int n;
    cout<<"Enter the nth fibo number needed"<<endl;
    cin>>n;

    fibo(n);

    return 0;
}