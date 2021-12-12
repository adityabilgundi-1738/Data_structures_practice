#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = INT_MIN;
        for (int i = 0; i < accounts[0].size(); i++){
            int wealth;
            for (int j = 0; j < accounts.size(); j++){
                wealth += accounts[j][i];
            }
            if(wealth > max){
                max = wealth;
            }
        }
        return max;
    }
};