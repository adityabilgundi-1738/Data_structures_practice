#include<bits/stdc++.h>
using namespace std;

static float pi = 3.14159265359;

void helper(){
    int r,a,b;
    cin>>r>>a>>b;
    int cur = r;
    double ans = 0;
    int step = 1;
    while(cur){
        ans += pi*cur*cur;
        if(step) cur = cur*a;
        else cur = cur/b;
        if(step) step = 0;
        else step = 1;
    }
    cout<<setprecision(8)<<ans<<endl;
}

int main(){
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
        cout<<"Case #"<<i<<": ";
        helper();
    }
    return 0;
}