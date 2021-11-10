#include<iostream>

using namespace std;

int main(){
    int a,b;
    cin>>a;
    cin>>b;
    string arr[10] = {"","one","two","three","four","five","six","seven","eight","nine"};

    for (int n = a; n<=b; n++){
        if (n<=9)
            cout<<arr[n]<<endl;
        if(n>9)
            cout<<((n%2==0)?"even":"odd")<<endl;     
    }
    return 0;
}
