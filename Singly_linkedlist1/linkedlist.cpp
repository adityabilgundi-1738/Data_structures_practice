#include<iostream>

using namespace std;

class node{
    public:
    int num;
    node *next;

    node(int num){//default constructor
        this -> num = num;
        next = NULL;
    }

};

void printer(node *head){
    //ideal printing loop bcs we might need head further
    node *temp = head; 
    while(temp!= NULL){
        cout<<temp->num<<" ";
        temp = temp->next; 
    }
    //head changes after printing soo non ideal
    // while(head != NULL){
    //     cout<<head->num<<" ";
    //     head  = head->next; 
    // }
}

int main(){
     //STATICALLY INITIALIZING LINKEDLIST
    node n1(45);
    node* head = &n1;//head is a pointer of type node

    node a(1);
    node b(1);
    node c(1);
    
    n1.next = &a;
    a.next = &b;
    b.next = &c;

    printer(head);//prints perfectly

    printer(head);//this also prints perfectly 
    //it doesnt matter that 'head' changes while printing as the function here passes the value of head
    //the function makes a copy of it and works on it
    
    //DYNAMICALLY INITIALIZING LINKEDLIST
    
    // node *n1 = new node(1);
    // node *n2 = new node(2);
    // node *n3 = new node(3);
    // node *n4 = new node(4);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = NULL;

    return 0;
}