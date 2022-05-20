#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 1e18;
// NO other possible way, O(n^2) is the only way

void helper(vector<long long>& vct, int len){
    int ans = INT_MAX;

    for (int i = 0; i < len; i++){
        int ans1 = 0;
        int prev = 0;

        for(int x = i-1; x >= 0; x--){
            int op = prev/vct[x];
            op++;
            ans1 += op;
            prev = vct[x]*op;
        }

        prev = 0;

        for(int x = i+1; x < len; x++){
            int op = prev/vct[x];
            op++;
            ans1 += op;
            prev = vct[x] * op;
        }
        ans = min(ans,ans1);
    }
    cout<<ans<<endl;
}

int main(){
    int len;
    cin>>len;
    vector<long long> vct;

    for(int i = 0; i < len; i++){
        int temp;
        cin>>temp;
        vct.push_back(temp);
    }
    helper(vct,len);

    return 0;
}