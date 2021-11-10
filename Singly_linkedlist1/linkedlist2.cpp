#include<iostream>

using namespace std;
//this code has time complexity of n^2
class node{
    public:
    int num;
    node* next;

    node(int num){//default constructor
        this -> num = num;
        next = NULL;
    }

};

void printer(node *head){
    node *temp = head; 
    while(temp!= NULL){
        cout<<temp->num<<" ";
        temp = temp->next; 
    }
}

node* takeinput(){
    int num;
    cin>>num;
    node* head = NULL;
    while(num != -1){
        node* newnode = new node(num);
        if(head == NULL){
            head = newnode;
        }
        else{
            node* temp = head;
            while(temp -> next != NULL){
                temp = temp ->next;
            }
            temp -> next = newnode;
        }
        cin>>num;
    }
    return head;

}

int main(){
    
    node* head  =takeinput();
    
    printer(head);
    
    return 0;
}