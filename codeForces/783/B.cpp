#include<bits/stdc++.h>
using namespace std;

void func(int n, long long m, vector<int>& vct){
    if(m<n){
        cout<<"NO\n";
        return;
    }
    sort(vct.begin(), vct.end());
    long long chairsReq = n;
    for(int i = 0; i < vct.size(); i++){
        if(i == vct.size() - 1){
            chairsReq += 2*vct[i] - vct[i-1] - vct[0];
        }
        else if(i == 0){
            chairsReq += 2*vct[0];
        }
        else{
            chairsReq += 2*vct[i] - vct[i-1];
        }
    }
    if(chairsReq <= m){
        cout<<"YES\n";
        return;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
}

int main(){
    int cases;
    cin>>cases;

    for(int i = 0; i < cases; i++){
        vector<int> vct;
        int n;
        long long m;
        cin>>n;
        cin>>m;
        for(int i = 0; i < n; i++){
            int temp;
            cin>>temp;
            vct.push_back(temp);
        }
        func(n,m,vct);
    }

    return 0;
}