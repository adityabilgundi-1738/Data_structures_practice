#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral (n, vector<int>(n,0));

        int top = 0, bottom = n-1, left = 0, right = n-1; 
        int dir = 0; //0 = go right, 1 = go down, 2 = go left, 3 = go up
        int temp = 1;

        while(top <= bottom && left <= right){
            if(dir == 0){
                for (int i = left; i <= right; i++){
                    spiral[top][i] = temp;
                    temp ++;
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top; i <= bottom; i++){
                    spiral[i][right] = temp;
                    temp++;
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right; i >= left; i--){
                    spiral[bottom][i] = temp;
                    temp++;
                }
                bottom--;
            }
            else if(dir == 3){
                for (int i = bottom; i >= top; i--){
                    spiral[i][left] = temp;
                    temp++;
                }
                left++;
            }
            dir = (dir + 1)%4;
        }

        return spiral;
    }
};