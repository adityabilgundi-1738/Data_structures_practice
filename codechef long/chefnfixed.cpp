#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    int n,x;
    cin>>n;
    cin>>x;

    int arr[n-1];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    //generating sum arr
    vector<int> sumarr;
    int temp;

    for (int i = 0; i < n; i++){
        for (int j = 1; j <= n - i; j++){
            temp +=arr[i];
            sumarr.push_back(sum);
        }

    }
    
    
    
}