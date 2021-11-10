#include<iostream>

using namespace std;

int factorial(int n){
    if(n == 1){
        return 1;
    }
    int smallOutput = factorial(n-1);
    return n*smallOutput;
}

int main(){
    int num;
    cin>>num;
    cout<<num<<"!"<<" is "<<factorial(num)<<endl;
    return 0;
}