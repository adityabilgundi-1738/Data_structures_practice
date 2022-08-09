#include<bits/stdc++.h>
using namespace std;

int main(){

    return 0;
}

class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<char,int>> s,t;
        
        for(int i = 0; i < start.size(); i++){
            if(start[i] != '_'){
                s.push_back(make_pair(start[i], i));
            }
        }
        
        for(int i = 0; i < target.size(); i++){
            if(target[i] != '_'){
                t.push_back(make_pair(target[i], i));
            }
        }
        
        if(s.size() != t.size()) return false;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i].first == t[i].first){
                if(s[i].first == 'L'){
                    if(s[i].second < t[i].second) return false;
                }
                else{
                    if(s[i].second > t[i].second) return false;
                }
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};