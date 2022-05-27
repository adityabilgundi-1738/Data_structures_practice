#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& mine){
    int m = mine.size();
    int n = mine[0].size();

    int dp[m][n];

    for(int i = m - 1; i >= 0; i++){
        dp[i][n-1] = mine[i][n-1];
    }

    for(int j = n - 2; j >= 0; j--){
        for(int i = m - 1; i >= 0; i--){
            if(i == 0){
                dp[i][j] = max(dp[i+1][j+1],dp[i][j+1]) + mine[i][j];
            }
            else if(i == m - 1){
                dp[i][j] = max(dp[i-1][j+1],dp[i][j+1]) + mine[i][j];
            }
            else{
                dp[i][j] = max(max(dp[i-1][j+1],dp[i+1][j+1]),dp[i][j+1]) + mine[i][j];
            }
        }
    }
    int max = INT_MIN;
    for(int i = 0; i < m; i++){
        if(dp[i][0] > max) max = dp[i][0];
    }

    return max;
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>> mine(m,vector<int>(n,0));
    cout<<solve(mine)<<endl;
    return 0;
}
