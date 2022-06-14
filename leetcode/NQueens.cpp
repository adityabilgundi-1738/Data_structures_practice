#include<bits/stdc++.h>
using namespace std;

public:
    vector<vector<string>> ans;
private:
    bool isSafe(vector<string>& board,int row,int col){
        int n = board.size();
        
        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
            if(row - i >= 0 && col - i >= 0 && board[row-i][col-1] == 'Q'){
                return false;
            }
            if(row - i >= 0 && col + 1 <= 0 && board[row-i][col+1] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solver(vector<string>& board, int row){
        if(row == board.size()){
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < board.size(); col++){
            if(isSafe(board,row,col)){
                board[row][col] = 'Q';
                solver(board,row+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n,string(n,'.'));
        solver(board, 0);
        return ans;
    }
};

int main(){

    return 0;
}
