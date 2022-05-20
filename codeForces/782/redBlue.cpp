#include<bits/stdc++.h>
using namespace std;

void printer(int tot, int r, int b){
    for(int i = 0; i < tot; i++){
        if(r != 0){
            cout<<"R"<<" ";
            r--;
        }
        else if( b != 0){
            cout<<"B"<<" ";
            b--;
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> vct;

    for(int i = 0; i < n; i++){
        int tot, r ,b;
        cin>>tot;
        cin>>r>>b;
    }

    return 0;
}