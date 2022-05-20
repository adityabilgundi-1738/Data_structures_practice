#include<bits/stdc++.h>
using namespace std;

void solve(int x, int y){
    int a = 0,b = 0;
    if(y%x == 0){
        a = 1;
        b = y/x;
    }
    cout<<a<<" "<<b<<endl;
    return;
}

int main(){
    int cases;
    cin>>cases;

    for(int i = 0; i < cases; i++){
        int n,m;
        cin>>n>>m;
        solve(n,m);
    }

    return 0;
} 