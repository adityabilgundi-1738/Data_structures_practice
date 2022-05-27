#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> vct,int target){
    int n = vct.size();
    bool dp[n + 1][target + 1];

    dp[0][0] = true;

    for(int i = 1; i <= target; i++){
        dp[0][i] = false;
    }
    
    for (int j = 1; j <= n; j++){
        dp[j][0] = true;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if(dp[i-1][j] == true){
                dp[i][j] = true;
            }
            else{
                int val = vct[i-1];
                if(i >= val){
                    if(dp[i-1][j-val] == true){
                        dp[i][j] = true;
                    }
                }
            }
        }
    }

    return dp[n][target];
}

int main(){
    vector<int> vct;
    int target;
    cin>>target;

    cout<<solve(vct,target)<<endl;
    return 0;
}
