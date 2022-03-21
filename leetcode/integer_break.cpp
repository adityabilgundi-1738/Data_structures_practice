#include<iostream>
#include<math.h>

using namespace std;

int solu(int n) {
    if(n == 1 || n == 2){
        return 1;
    }
    if(n == 3){
        return 2;
    }

    int rem = n%3;
    int no_3 = n/3;
        
    if(rem == 1){
        return pow(3,no_3-1)*4;
    }
    if(rem == 2){
        return pow(3,no_3)*2;
    }
    if(rem == 0){
        return pow(3,no_3);
    }
    return  0;
}

int main(){
    int n;
    cin>>n;
    cout<<solu(n)<<endl;

    return 0;
}   

