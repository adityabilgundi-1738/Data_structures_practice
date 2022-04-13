#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s){
    vector<int> partitionLabels(string s){
    unordered_map<char,int> map;
    for(int i = 0; i < s.length(); i++){
        map[s[i]] = i;
    }

    vector<int> ret;

    int x = 0, y = s.length(); 
    while(x != y){
        int last_occ = map[s[x]];
        int temp = last_occ - x;
        while(temp--){
            if(map[s[x]] < last_occ){
                continue;
            }
            else{
                last_occ++;
                ++temp;
            }
        }
        ret.push_back(last_occ);
        x += last_occ + 1;
    }
    return ret;
    }
}   