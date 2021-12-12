#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    pair<int,int> minMax(vector<int>& nums){
        int min = nums[0],max = nums[0];
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] > max){
                max = nums[i];
            }
            else if(nums[i] < min){
                min = nums[i];
            }
            else if((nums[i] < max) && (nums[i] > min)){
                continue;
            }
        }
        pair<int,int> res;
        res.first = min;
        res.second = max;
        return res;
    };
    int findGCD(vector<int>& nums){
        int gcd = 1;
        pair<int,int> limits = minMax(nums);
        
        limits.first = limits.first > -limits.first ? limits.first:-limits.first;
        limits.second = limits.second > -limits.second ? limits.second:-limits.second;
        for(int i=1 ; i<=limits.first && i<=limits.second ; ++i)
        {
            if( limits.first%i ==0 && limits.second%i ==0 )
            {
                gcd = i;
            }
        }
        return gcd;
    };
};