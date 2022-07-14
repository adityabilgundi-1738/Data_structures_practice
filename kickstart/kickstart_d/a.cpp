#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> vec, int n, int m){
    if(n == m){
        sort(vec.begin(), vec.end());
        cout<<accumulate(vec.begin(), vec.end(), 0)<<endl;
    }
    else{
        int sum = accumulate(vec.begin() + 2, vec.end(), 0);
        sum += (vec[0] + vec[1])/2;
        cout<<sum<<endl;
    }
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int n, m;
        vector<int> vec;
        for(int i = 0; i < n; i++){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }
        cout<<"Case #"<<i<<": ";
        solve(vec,n,m);
    }
    return 0;
}