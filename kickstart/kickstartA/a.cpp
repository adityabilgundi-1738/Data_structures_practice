#include<bits/stdc++.h>
using namespace std;

void helper(){
    string a, b;
    cin >> a >> b;
    int cur = 0;
    for(int i = 0; i < a.size(); ++i) {
        while(cur < b.size() && b[cur] != a[i]) {
            ++cur;
        }
        if(cur == b.size()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        ++cur;
    }   
    cout << b.size() - a.size() << "\n";
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