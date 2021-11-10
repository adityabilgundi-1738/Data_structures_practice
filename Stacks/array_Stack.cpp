#include<iostream>
#include<climits>

using namespace std;

class stack{
    int* data;
    int nextindex;
    int capacity;
    
    public:

    stack(int size){//def constructor
        data = new int[size];
        nextindex = 0;
        capacity = size;
    }

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex == 0;
    }
    //insert element
    void push(int element){//push
        if(nextindex == capacity){
            cout<<"Stack FULL"<<endl;
            return;
        }
        else{
            data[nextindex] = element;
            nextindex++;
        }
    }
    //delete element
    int pop(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }
    //returns value of top element doesnt pop it
    int top(){
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextindex-1];
    }

};

int main(){

    stack s(10);//size  = 10
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    //stack is now = 10,20,30,40,50 

    s.pop();//50 is out
    s.push(100);
    //stack is now = 10,20,30,40,100
    s.pop();//100 is out


    //all 3 are same

    s.top();
    s.top();
    s.top();
    
    s.isempty();


    return 0;
}