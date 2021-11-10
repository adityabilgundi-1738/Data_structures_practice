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
    node* tail = NULL;
    while(num != -1){
        node* newnode = new node(num);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        cin>>num;
    }
    return head;
}

node* midpoint(node* head){
    node* slow = head;
    node* fast = head->next;

    if(head != NULL)
    {
        while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        }
    }
    return slow;
}

void nodeprinter(node* n){
    cout<<n->num<<endl;
}

int main(){
    node* head = takeinput();
    //printer(head);
    node* midpt = midpoint(head);
    nodeprinter(midpt);

    return 0;
}