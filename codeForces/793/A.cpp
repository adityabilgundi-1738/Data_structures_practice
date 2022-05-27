#include<bits/stdc++.h>
using namespace std;

int solve(int n,string s){
    int count = 0; 
    for(int i = n/2; i >= 0; i--){
        if(s[n/2] == s[i]){
            count++;
        }
        else{
            break;
        }
    }
    for(int i = n/2; i < n; i++){
        if(s[n/2] == s[i]){
            count++;
        }
        else{
            break;
        }
    }
    return count - 1;
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<solve(n,s)<<endl;
    }
    return 0;
}