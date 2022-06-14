// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long>ans;
    queue<long long>list;
    long long i=0,j=0;
    while(j<N){
        if(A[j] < 0){
            list.push(A[j]);
        }
        
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            if(list.empty() == false){
                ans.push_back(list.front());
            }
            else{
                ans.push_back(0);
            }
            if(A[i] == list.front()){
                list.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans;
    queue<long long> list;
    
    long long i = 0,j = 0;
    
    while(j < N){
        if(A[j] < 0){
            list.push(A[j]);
        }
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            if(list.empty() == 1){
                ans.push_back(0);
            }
            else{
                ans.push_back(list.front());
            }
            if(A[i] == list.front()){
                list.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main(){

    return 0;
}