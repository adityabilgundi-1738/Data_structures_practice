#include<iostream>

using namespace std;

int minsteps(int n){
    int x = n-1,y = 0,z = 0;
    x = minsteps(x);

    if(n%2 == 0){
        int y = n/2;
        y = minsteps(y);
    }

    if(n%2 == 0){
        int z = n/3;
        z = minsteps(z);
    }
    return min(x,min(y,z)) + 1;
}

int main(){
    int n;
    cin>>n;

    cout<<minsteps(n)<<endl;
    return 0;
}