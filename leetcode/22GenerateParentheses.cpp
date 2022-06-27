#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = n;
        int close = n;
        string str;

        helper(open,close,ans,str);
        return ans;
    }
    
    void helper(int open, int close, vector<string>& vec, string& op){
        if(open == 0 && close == 0){
            vec.push_back(op);
            return;
        }

        if(open != 0){
            string op1 = op;
            op1.push_back('(');
            helper(open - 1, close, vec, op1);

        }

        if(close > open){
            string op2 = op;
            op2.push_back(')');
            helper(open, close - 1, vec, op2);
        }
    }
};

int main(){

    return 0;
}