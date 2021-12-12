#include<vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> shuffled;
        for (int i = 0, j = n; i < n; i++, j++){
            shuffled.push_back(nums.at(i));
            shuffled.push_back(nums.at(j));
        }
        return shuffled;
    }
};
