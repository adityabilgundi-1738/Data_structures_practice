#include<iostream>
#include<climits>

using namespace std;

class stack{
    int* data;
    int nextindex;
    int capacity;
    
    public:

    stack(){//def constructor
        data = new int[4];
        nextindex = 0;
        capacity = 4;
    }

    int size(){
        return nextindex;
    }

    bool isempty(){
        return nextindex == 0;
    }
    
    void push(int element){//add elements to the stack
        if(nextindex+1 == capacity){//resizing
            int* newdata = new int[2*capacity];//creating double cap arr
            for (int i = 0; i < capacity; i++){//copying to new
                newdata[i] = data[i];
            }
            capacity*=2;
            delete [] data;
            data = newdata;
        }
        else{
            data[nextindex] = element;
            nextindex++;
        }
    }
    
    int pop(){//delete element
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }

    int top(){//return top element
        if(isempty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextindex-1];

    }

};


int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //s.push(60);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    
    cout<<s.isempty()<<endl;

    return 0;
}