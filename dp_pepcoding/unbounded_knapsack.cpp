#include<bits/stdc++.h>
using namespace std;

void solve(int k,vector<int> values,vector<int> weights){
    int dp[values.size()+1][k+1];

    dp[0][0] = 0;

    for (int i = 1; i <= k; i++){
        dp[0][i] = dp[0][i-1];
    }

    for(int i = 1; i <= values.size(); i++){
        dp[i][0] = dp[i-1][0];
    }

    for(int i = 1; i <= values.size(); i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            
            if(weights[i-1] <= j){//the remaining size in the knapsack is more than or equal to the value
                dp[i][j] = max(values[i-1] + dp[i][j-weights[i - 1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    

}

int main(){
    
    return 0;
}