#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    int row,col;
    vector<vector<int>> store;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        store = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        store[0][0] = matrix[0][0];
        for(int i = 1; i < matrix.size(); i++){
            store[i][0] = store[i-1][0] + matrix[i][0];
        }
        for(int i = 1; i < matrix[0].size(); i++){
            store[0][i] = store[0][i - 1] + matrix[0][i];
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                store[i][j] = store[i-1][j] + store[i][j-1] - store[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return store[row2][col2] - store[row1-1][col2] - store[row2][col1 - 1] + store[row1 - 1][col1 - 1];
    }
};

int main(){

    return 0;
}