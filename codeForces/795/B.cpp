#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<long long>& vct){
    bool equal = true;
    for(int i = 0; i < n - 1; i++){
        if(vct[i] != vct[i+1]){
            equal = false;
        }
    }
    if(equal == false){
        cout<<-1<<endl;
    }
    else{
        for(int i = n; i > 0; i--){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<long long> vct;
        for(int i = 0; i <n; i++){
            long long temp;
            cin>>temp;
            vct.push_back(temp);
        }
        solve(n,vct);
        
    }
    return 0;
}