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

void reverseprinter(node* head){
    if(head == NULL)
    return;
    
    reverseprinter(head->next);
    cout<<head->num<<" ";
}

int main(){
    node* head = takeinput();
    cout<<endl;

    reverseprinter(head);
    return 0;

}