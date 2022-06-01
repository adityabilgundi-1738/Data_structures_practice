#include<bits/stdc++.h>
using namespace std;

int solve(int n,string s){
    int count = 0;
    int changes = 0;
    char c;

    for(int i = 0; i < n; i++){
        if(i == 0){
            c = s[0];
            count++;
            continue;
        }

        if(count == 0){
            count++;
            c = s[i];
            continue;
        }

        if(s[i] == c){
            count++;
        }
        else{
            if(count % 2 == 1){//odd
                count = 0;
                changes++;
            }
            else if(count % 2 == 0){//even
                count = 1;
                c = s[i];
            }
        }
    }
    return changes;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        long long n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(n,s)<<endl;
    }
    return 0;
}