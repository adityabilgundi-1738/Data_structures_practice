#include<bits/stdc++.h>
using namespace std;

void helper()
{
    string s;
    cin >> s;
    int sum = 0;
    for(auto j:s) {
        sum += j - '0';
    }
    sum %= 9;
    if(sum != 0) {
        int ans = 9 - sum;
        int did = false;
        for(int i=0;i<s.size();++i) {
            if(s[i] - '0' > ans && !did) {
                cout << ans << s[i];
                did = true;
            }
            else {
                cout << s[i];
            }
        }
        if(!did) {
            cout << ans << "\n";
        }
        else {
            cout << "\n";
        }
    }
    else {
        cout << s[0];
        int did = false;
        for(int i=1;i<s.size();++i) {
            if(s[i] - '0' > 0 && !did) {
                cout << 0 << s[i];
                did = true;
            }
            else {
                cout << s[i];
            }
        }
        if(!did) {
            cout << 0 << "\n";
        }
        else {
            cout << "\n";
        }
    }
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