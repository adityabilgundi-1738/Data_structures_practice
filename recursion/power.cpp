#include<iostream>

using namespace std;

int powerfunc(int x,int n){
    if(n == 1){
        return x;
    }
    return x*powerfunc(x,n-1);
}
int main(){
    cout<<"Enter x & n"<<endl;
    int x,n;
    cin>>x>>n;
    cout<<endl;
    powerfunc(x,n);
    cout<<powerfunc(x,n)<<endl;
    return 0;
}