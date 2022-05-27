#include<bits/stdc++.h>
using namespace std;

int solve_helper(int n, vector<int>& arr, int* dp){//memo helper
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--){
        if(arr[i] > 0){
            int mini = INT_MAX;

            for(int j = 1; (j <= arr[i]) && (i+j < n+1); j++){
                if(dp[i+j] != NULL){
                    mini = min(mini,dp[i+j]);
                }
            }

            if(mini != INT_MAX){
                dp[i] = mini + 1;
            }
            else{
                dp[i] = NULL;
            }
        }
    }

    return dp[0];
}

void solve(int n, vector<int>& arr){//memo
    int* dp = new int[n+1];
    cout<<solve_helper(n, arr, dp)<<endl;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr;
    for (int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    
    solve(n,arr);

    return 0;
}