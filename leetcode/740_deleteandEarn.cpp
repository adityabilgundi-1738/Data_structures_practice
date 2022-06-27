#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(vector<int>& vec){
        int n = vec.size();
        
        vector<int> dp(n,0);
        dp[0] = vec[0];
        dp[1] = max(dp[0], vec[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], vec[i]*i + dp[i-2]);
        }
        return vec[n-1];
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<int> vec(*max_element(nums.begin(),nums.end()) + 1, 0);
        for(auto it: nums){
            vec[it]++;
        }
        
        return helper(vec);
    }
};

int main(){

    return 0;
}