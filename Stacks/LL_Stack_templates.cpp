#include<iostream>
using namespace std;
#include"stackUsingLL.h"

int main(){
    stack <char> a;
    // stack <int> a;
    // stack <bool> a;
    // stack <double> a;
    a.push('a');
    a.push('b');
    a.push('c');
    a.push('d');
    a.push('e');
    a.push('f');
    

    cout<<"size = "<<a.size()<<endl;

    cout<<a.first()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.first()<<endl;
    cout<<a.pop()<<endl;
    cout<<a.first()<<endl;

    cout<<"size = "<<a.size()<<endl;
    cout<<"empty? = "<<a.isempty()<<endl;

    return 0;
}