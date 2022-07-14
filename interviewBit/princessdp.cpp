#include<bits/stdc++.h>
using namespace std;

int calculateMinimumHP(int** A, int m, int n){
    int dp[m][n];
    dp[m-1][n-1] = A[m-1][n-1];
    
    for(int i = m - 1; i >= 0; i--){
        dp[i][0] = dp[i+1][0] + A[i][0] > 0 ? 0 : dp[i+1][0] + A[i][0];
    }
    
    for(int i = n - 1; i >= 0; i--){
        dp[0][i] = dp[0][i+1] + A[0][i] > 0 ? 0 : dp[0][i+1] + A[0][i];
    }
    
    for(int i = m - 1; i >= 0; i--){
        for(int j =  n - 1; j >= 0 ; j--){
           dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + A[i][j];
        }
    }
    
    return -dp[0][0] + 1;
}

int main(){
    
    return 0;
}