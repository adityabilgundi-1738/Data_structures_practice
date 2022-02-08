#include<iostream>
#include<vector>
using namespace std;

vector<int> deci2bin(int n){
    vector<int> ans;
    while(n > 0){
        ans.push_back(n%2);
        n = n/2;
    }
    return ans;
}
vector<int> countBits(int n) {
    vector<int> arr_values;
    for(int i = 0; i <= n; i++){
        arr_values[i] = -1;
    }
        
    vector<int> ans;
        
    for(int i = 0; i <= n ;i++){
        if(arr_values[i] == -1){
            vector<int> temp = deci2bin(i);
            int ones = 0;
            for(int j = 0; j < temp.size(); j++){
                if(temp[j] == 1){
                        ones++;
                }
            }
            arr_values[i] = ones;
            ans[i] = ones;
        }
        else{
             ans[i] = arr_values[i];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> ans = countBits(n);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    
}
