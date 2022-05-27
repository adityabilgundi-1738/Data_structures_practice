#include<bits/stdc++.h>
using namespace std;

// number of different paths one can take to climb to the top given 'n' as the total number of stairs
// one can take 1,2 or 3 stairs at a time

int solve(int n, int arr []){//memoization
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        return 0;
    }
    if(arr[n] > 0){
        return arr[n];
    }
    int num =  solve(n-1,arr) + solve(n-2,arr) + solve(n-3,arr);
    arr[n] = num;
    return num;
}

int dp(int n){//tabulation
    int arr [n+1];
    arr[0] = 1;
    
    for (int i = 0; i < n; i++){
        if(i == 1){
            arr[i] =  arr[i-1];
        }
        else if(i == 2){
            arr[i] =  arr[i-1] + arr[i-2];
        }
        else{
            arr[i] =  arr[i-1] + arr[i-2] + arr[i-3];
        }
    }
    
    return arr[n];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<solve(n, arr)<<endl;
    return 0;
}