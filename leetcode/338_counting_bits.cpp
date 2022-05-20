#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> deci2bin(int n){
        vector<int> ans;
        while(n > 0){
            ans.push_back(n%2);
            n = n/2;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> binary_ones_storage(n+1, -1);
        vector<int> ans;
        
        for(int i = 0; i <= n ;i++){
            if(binary_ones_storage[i] == -1){
                vector<int> temp = deci2bin(i);
                int ones = 0;
                for(int j = 0; j < temp.size(); j++){
                    if(temp[j] == 1){
                            ones++;
                    }
                }
                binary_ones_storage[i] = ones;
                ans[i] = ones;
            }
            else{
                ans[i] = binary_ones_storage[i];
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> ans = countBits(n);

    
    return 0;
}

