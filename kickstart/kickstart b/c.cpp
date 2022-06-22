#include <bits/stdc++.h>
using namespace std;

long long dp[500][500][2];
vector<long long> vec;
long long n,d;

long long solve(long long l, long long r, long long dir){
    if(l > r){
        return 0;
    }
    if(dp[l][r][dir] != -1){
        return dp[l][r][dir];
    }
    
    long long x;
    if(dir == 0){
        x = (vec[l] - vec[l-1] + d) % d;
    }
    else{
        x = (vec[l] - vec[r+1] + d) % d;
    }
    
    long long y;
    if(dir == 0){
        y = (vec[r] - vec[l-1] + d) % d;
    }
    else{
        y = (vec[r] - vec[r+1] + d) % d;
    }
    
    long long ans = min(min(y,d-y) + solve(l, r-1, 1), min(x,d-x) + solve(l+1, r, 0));
	dp[l][r][dir] = ans;
    return ans;
}

int main(){
    long long t;
    cin>>t;
    long long T = 1;

    while(t--){
        cin>>n>>d;
        vec.resize(n);
        
        for(long long i = 0; i < n; i++){
            cin>>vec[i];
        }
        
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        long long a1 = min(vec[0], d - vec[0]) + solve(1, n - 1, 0);
        long long a2 = min(vec[n - 1], d - vec[n - 1]) + solve(0, n - 2, 1);
        long long ans = min(a1,a2);
        
        cout << "Case #" << T << ": " << ans << "\n";
		T++;
    }
}   