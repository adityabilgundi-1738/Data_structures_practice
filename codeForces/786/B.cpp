#include<bits/stdc++.h>
using namespace std;

void solve(string s){
    char f = s[0];
    char d = s[1];
    int ha = f - 96;
    ha = (ha - 1)*26 - ha - 1;
    ha += d - 96;
    cout<<ha<<endl;
}

int main(){
    int cases;
    cin>>cases;

    for(int i = 0; i < cases; i++){
        string s;
        cin>>s;
        solve(s);
    }

    return 0;
} 