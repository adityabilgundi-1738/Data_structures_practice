#include<bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k, vector<long long>& bruh){
    if(n == k) return 0;

    for(long long i = 0; i < k; i++){
        auto it = max_element(bruh.begin(), bruh.end());
        *it = -1;
    }

    long long z = 0,factor = 0;
    for(long long i = 0; i < bruh.size(); i++){
        if(bruh[i] == -1){
            factor++;
        }
        else{
            z += bruh[i] + factor;
        }
    }
    return z;
}

int main(){
    long long cases;
    cin>>cases;
    for(long long i = 0; i < cases; i++){
        long long n,k;
        cin>>n;
        cin>>k;

        vector<long long> bruh(n,0);
        for(long long i = 0; i < n; i++){
            long long t;
            cin>>t;
            bruh[i] = t;
        }
        cout<<solve(n,k,bruh)<<endl;
    }
    return 0;
}