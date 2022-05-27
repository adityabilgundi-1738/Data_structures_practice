#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> perm){
    int z = 1;
    for(int i = 0; i < n; i++){
        if(perm[i] != i){
            z &= perm[i];
        }
    }
    return z;
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int n;
        vector<int> perm;
        for(int i = 0; i < n;i++){
            int t;
            cin>>t;
            perm.push_back(t);
        }
        cout<<solve(n,perm)<<endl;
    }
    return 0;
}