#include<iostream>
#include<stack>

using namespace std;

stack<int> a;
stack<int> secondstack;

void duplicatestack(){
    int ele;
    if(!a.empty()){
        ele = (a.top());
        a.pop();
        secondstack.push(ele);
        duplicatestack();
    }
}

void reverse(){
    while(!secondstack.empty()){
        a.push(secondstack.top());
        secondstack.pop();
    }
}


int main(){
    

    // // a.push(10);
    // // a.push(9);
    // // a.push(8);
    // // a.push(7);
    // // a.push(6);
    // // a.push(5);
    // a.push(4);
    // a.push(3);
    // a.push(2);
    // a.push(1);


    return 0;
}