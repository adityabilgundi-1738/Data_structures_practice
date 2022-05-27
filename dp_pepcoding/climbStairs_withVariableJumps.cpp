#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> arr){//tabulation  - top to bottom
    int dp[n+1];
    dp[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; (j <= arr[i]) && (i + j < n+1); j++){
            dp[i] = dp[i+j];
        }
    }
    return dp[0];
}

int memoHelp(int n, vector<int>& arr, vector<int>& memo, int k){//memoize - bottom to top
    if(k > n){
        return 0;
    }
    if(k == n){
        return 1;
    }
    if(memo[k] != 0){
        return memo[k];
    }
    
    int res = 0;
    for(int i = 0; i < arr[k]; i++){
        res += memoHelp(n,arr,memo,k+i);
    }

    memo[k] = res;
    return res;
}

int memoise(int n, vector<int> arr){
    vector<int> memo(n+1,0);
    memoHelp(n,arr,memo,0);
}

int main(){
    int n;
    vector<int> arr;
    cin>>n;
    for(int i = 0;i < n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    solve(n,arr);
    return 0;
}