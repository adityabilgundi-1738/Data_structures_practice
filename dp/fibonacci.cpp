#include<iostream>
using namespace std;

int reg_fibo(int n){
    if(n <= 1){
        return n;
    }
    int a = reg_fibo(n-1);
    int b = reg_fibo(n-2);

    return a+b;
}

int fibo_helper(int n, int* arr){
    if(n <= 1){
        return 1;
    }
    if(arr[n] != -1){
        return arr[n];
    }
    else{
        arr[n] = reg_fibo(n);
        return arr[n];
    }
}

int fibo(int n){
    int* arr = new int[n+1];
    for (int i = 0; i <= n; i++){
        arr[i] = -1;
    }
    fibo_helper(n,arr);
}

int main(){
    int n;
    cin>>n;

    cout<<n<<"th fibonacci Number = "<<fibo(n)<<endl;

    return 0;
}