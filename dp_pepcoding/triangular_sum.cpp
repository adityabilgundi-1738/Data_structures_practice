#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> original = nums;
        vector<int> dp;
        for(int j = 0; j < nums.size() - 1; j++){
            for(int i = 0; i < original.size(); i++){
                dp.push_back((original[i]+original[i+1])%10);
            }
            original.clear();
            original = dp;
            dp.clear();
        }
        return original[0];
    }
};

int main(){

    return 0;
}