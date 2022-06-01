#include<bits/stdc++.h>
using namespace std;

int solve(int a,vector<int>& vct){
    int odd = 0,even = 0;
    for(auto it: vct){
        if(it%2 == 0){
            even++;
        }
        else odd++;
    }
    return min(odd,even);
}

int main(){
    int t;
    cin>>t;
    
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<int> vct;
        for(int i = 0; i < n; i++){
            int haha;
            cin>>haha;
            vct.push_back(haha);
        }
        cout<<solve(n,vct)<<endl;
    }
    return 0;
}