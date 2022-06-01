#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        for(int i = 0; i < s.size() - k + 1; i++){
            set.insert(s.substr(i,k));
        }
        if(set.size() == pow(2,k)){return 0;}
        else{
            return false;
        }
    }
};

int main(){

    return 0;
}