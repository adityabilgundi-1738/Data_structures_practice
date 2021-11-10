#include<iostream>

using namespace std;

void printer(const int n){//call stack i.e: first in last out
    if(n>=1)
    printer(n-1);
    else
    return;
    cout<<n<<endl;
}

int main(){
    cout<<"Enter n"<<endl;
    int n;
    cin>>n;
    printer(n);

    return 0;
}