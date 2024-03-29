#include<bits/stdc++.h>
using namespace std;

// int minPathSum(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();

//     vector<vector<int>> dp(m,vector<int>(n,0));

//     for(int i = dp.size() - 1; i >= 0; i--){
//         for(int j = dp[0].size(); j >= 0; j--){
//             if((i == dp.size() - 1) && (j = dp[0].size() - 1)){
//                 dp[i][j] = grid[i][j];
//             }
//             else if(i == dp.size() - 1){
//                 dp[i][j] = dp[i][j + 1] + grid[i][j];
//             }
//             else if(j == dp.size() - 1){
//                 dp[i][j] = dp[i+1][j] + grid[i][j];
//             }
//             else{
//                 dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
//             }
//         }
//     }
// }

int minPathSum(vector<vector<int>>& grid) {//memoization
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m,vector<int>(n,0));

    dp[m-1][n-1] = grid[m-1][n-1];

    for(int i = n - 2; i >= 0; i--){//last row
        dp[m-1][i] = dp[m-1][i+1] + grid[m-1][i];  
    }

    for(int i = m - 2; i >= 0; i--){//last column
        dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1];  
    }

    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
        }
    }

    return dp[0][0];
}

int main(){

    return 0;
}