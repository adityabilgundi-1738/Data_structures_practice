#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }
        int l = 0;
        int r = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int totAns = 0;
        
        while(l < r){
            if(height[l] < height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }
                else{
                    totAns += leftMax - height[l];
                }
                l++;
            }
            else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }
                else{
                    totAns += rightMax - height[r];
                }
                r--;
            }
        }
        return totAns;
    }
};

int main(){

    return 0;
}
