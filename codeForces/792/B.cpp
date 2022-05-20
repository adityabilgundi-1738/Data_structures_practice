#include<bits/stdc++.h>
using namespace std;

int main(){
    long long cases;
    cin>>cases;

    for(long long i = 0; i < cases; i++){
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<a+b+c<<" "<<b+c<<" "<<c<<endl;
    }

    return 0;
}