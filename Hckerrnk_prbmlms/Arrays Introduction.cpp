#include<iostream>
using namespace std;

int main(){
    int n,*arr;
    cin>>n;
    arr = new int[n];

    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for (int i = 0; i < n; i++){
        cout<<arr[n-i-1];
    }
    
    return 0;
    
    
}