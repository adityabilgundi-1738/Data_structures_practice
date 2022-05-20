#include<bits/stdc++.h>
using namespace std;

int minSteps(int n, int m){
    //edge cases
    if(n == 1 || m == 1){
        if(abs(n-m) >= 2){
            return -1;
        }
    }

    int steps = 0;
    steps += min(n,m) * 2 - 2;

    int check = max(n,m) - min(n,m);
    if(check%2 == 0){
        steps += check*2;
    }
    else{
        steps += check*2 - 1;
    }

    return steps;
}  

int main(){
    int cases;
    cin>>cases;

    for(int i = 0; i < cases; i++){
        int n,m;
        cin>>n>>m;
        cout<<minSteps(n,m)<<endl;
    }

    return 0;
}