#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= amount; i++){
            for (int coin : coins){
                if(coin <= i){
                    dp[i] += dp[i-coin];
                }
            }
        }
        return dp[amount];
    }
};

int main(){

    return 0;
}