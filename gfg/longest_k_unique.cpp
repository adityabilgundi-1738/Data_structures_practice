#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> umap;
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int n = sizeof(s)/sizeof(char);
        
        while(j < n){
            if(umap.find(s[j]) == umap.end()){//encountered a new character
                if(umap.size() == k){
                    ans = max(ans,j-i);
                    char temp = s[i];
                    while(umap[temp] > 0){
                        umap[s[i]]--;
                        i++;
                    }
                    for(auto it: umap){
                        if(it.second == 0){
                            umap.erase(it.first);
                        }
                    }
                    umap[s[j]]++;
                }
                else{
                    umap[s[j]]++;
                }
                j++;
            }
            else{//encountered a similar char
                umap[s[j]]++;
                j++;
            }
        }
        return ans;
    }
};

int main(){
    unordered_map<int,int> umap;
    umap[1] = 0;
    umap[6] = 0;
    umap[2] = 0;
    umap.erase(1);
    umap.erase(6);
    umap.erase(2);
    cout<<umap.size()<<endl;
    return 0;
}