#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = sqrt(matrix.size());
        vector<int> spiral_to_vct (n,0);

        int top = 0, bottom = n-1, left = 0, right = n-1; 
        int dir = 0; //0 = go right, 1 = go down, 2 = go left, 3 = go up

        while(top <= bottom && left <= right){
            if(dir == 0){
                for (int i = left; i <= right; i++){
                    spiral_to_vct.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top; i <= bottom; i++){
                    spiral_to_vct.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right; i >= left; i--){
                    spiral_to_vct.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(dir == 3){
                for (int i = bottom; i >= top; i--){
                    spiral_to_vct.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1)%4;
        }

        return spiral_to_vct;
    }
};