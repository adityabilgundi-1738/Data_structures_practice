#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> arr;
        int i = 0;
        while(nums.size() != arr.size()){
            arr.push_back(nums[nums[i]]);
            i++;
        }
        return arr;
    }
};