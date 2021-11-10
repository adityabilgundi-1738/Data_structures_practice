#include<iostream>

using namespace std;

class node{
    public:

    int num;
    node* next;
    node(int num){
        this->num = num;
        next = NULL;
    }
};

class stack{
    public:
    node* top;

    stack(){//def constructor
        top = NULL;
    }

    node* push(int num){
        node* temp = new node(num);
        if(top == NULL){
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
            temp = NULL;
            delete [] temp;
        }
        return top;
    }

    int first(){
        return top->num;
    }

    int pop(){
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }

        node* temp = top;
        top = top->next;
        int n =  temp->num;
        delete [] temp;// deleteing is important
        return n;
    }
    
    int size(){
        node* temp = top;
        if(temp == NULL){
            return 0;
        }
        int count = 1;
        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool isempty(){
        if(top == NULL){
            return true;
        }
        else
        return false;
    }
};

int main(){
    stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);

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