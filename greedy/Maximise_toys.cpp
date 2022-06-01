#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/maximize-toys0331/1/?category

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr){
        sort(arr.begin(),arr.end());
        int ans = 0;
        
        for(int i = 0; i < N; i++){
            if(arr[i] <= K){
                ans++;
                K -= arr[i];
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}