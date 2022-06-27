#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> dp;
    bool canJump(vector<int>& nums){
        int n = nums.size();
        dp.assign(n, -1);
        
        return helper(0,nums);
    }
    
    bool helper(int i, vector<int>& nums){
        if(i == nums.size() - 1){
            return true;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        for(int j = i+1; j <= i + nums[i]; j++){
            if(helper(j,nums)){
                dp[i] = true;
                return dp[i];
            }
        }
        return dp[i] = false;
    }
};

int main(){

    return 0;
}