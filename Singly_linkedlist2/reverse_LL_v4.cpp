#include<iostream>

using namespace std;

class node{
    public:
    node* next;
    int num;

    node(int num){
        next = NULL;
        this->num = num;
    }

};

node* takeinput(){
    int num;
    cin>>num;

    node* head = NULL;
    node* tail = NULL;
    while(num != -1){
        node* newnode = new node(num);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
        cin>>num;
    }

    return head;
}

void printer(node* head){
    while(head != NULL){
        cout<<head->num<<" ";
        head = head->next;
    }
}

node* reversal(node* head){
    node* prev = NULL;
    node* curr = head;
    node* foll = head->next;

    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = foll;
        if(foll != NULL){
            foll = foll->next;
        }
    }
    return prev;
}

int main(){
    node* head = takeinput();
    printer(head);
    cout<<endl;
    head = reversal(head);
    printer(head);
    cout<<endl;

    return 0;
}
