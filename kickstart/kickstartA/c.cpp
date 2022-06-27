#include<bits/stdc++.h>
using namespace std;

void helper(){
    int n;
    cin>>n;
    string s1;
    cin>>s1;

    string s2 = s1;
    for (int i = 0; i < n / 2; i++){
        swap(s2[i], s2[n - i - 1]);
    }

    for(int i = 0; i < n/2; i++){
        if(s1[i] == s2[i]){
            continue;
        }
        else{
            cout<<"POSSIBLE"<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}

int main(){
    long long T;
    cin>>T;
    for(long long i = 1; i <= T; i++){
        cout<<"Case #"<<i<<": ";
        helper();
    }
    return 0;
}