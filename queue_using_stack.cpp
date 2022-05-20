#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2; 
    MyQueue() {
        
    }

    void push(int x) {
        s1.push(x);
    }

    void transfer(stack<int> &s1,stack<int> &s2){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int pop() {
        transfer(s1,s2);
        int x = s2.top();
        s2.pop();
        transfer(s2,s1);
        return x;
    }

    int peek() {
        transfer(s1,s2);
        int x = s2.top();
        transfer(s2,s1);
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){

    return 0;
}