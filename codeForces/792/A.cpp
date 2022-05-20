#include<bits/stdc++.h>
using namespace std;

vector<int> integerToArray(int x){
    vector<int> resultArray;
    while(true){
        resultArray.insert(resultArray.begin(), x % 10);
        x /= 10;
        if(x == 0) return resultArray;
    }
}

void solve(int n){
    vector<int> s = integerToArray(n);

    if(s.size() == 2) cout<<s[1]<<endl;
    else{
        int temp = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            if(s[i] < temp) temp = s[i];
        }
        cout<<temp<<endl;
    }
    return;
}

int main(){
    int cases;
    cin>>cases;

    for(int i = 0; i < cases; i++){
        int n;
        cin>>n;
        solve(n);
    }

    return 0;
}