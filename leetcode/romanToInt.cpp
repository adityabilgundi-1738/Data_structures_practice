#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    int romanToInt(string s){
        unordered_map<char,int> conv = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++){
            if(conv[s[i]] < conv[s[i+1]]){
                sum -= conv[s[i]];
            }
            else{
                sum += conv[s[i]];
            }
        }
        sum += conv[s.back()];

        return sum;
    }
};