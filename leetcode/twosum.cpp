#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    vector<int> temp;
    unordered_map<int,int> tempmap;
    for (int i = 0; i < nums.size(); i++){
        tempmap[nums[i]] = i;
    }
    
    sort(nums.begin(), nums.end());
    while (i < j)
    {
        if (nums[i] + nums[j] == target)
        {
            temp.push_back(tempmap[nums[i]]);
            temp.push_back(tempmap[nums[j]]);
            return temp;
        }
        else if (nums[i] + nums[j] < target)
        {
            ++i;
        }
        else
            --j;
    }
    temp.clear();
    return temp;
}

int main(){
    vector<int> tempp;
    tempp.push_back(3);
    tempp.push_back(2);
    tempp.push_back(4);
    vector<int> ans = twoSum(tempp,6);
    int i = ans.size();
    // while(i--){
    //     cout<<ans[i]<<", ";
    // }
    return 0;
}