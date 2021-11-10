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

int length(node* head){
    int count = 1;
    while(head->next != NULL){
        count++;
        head = head->next;
    }
    return count;
}

node* move_N_nodes(node* head, int n){
    node* temp = head;
    if(length(head) == n){
        cout<<"Use reversal Program"<<endl;
        return head;
    }
    int count = length(head)-n;

    for (int i = 1; i < count; i++){
        temp = temp->next;
    }
    node* h2 = temp->next;
    temp->next = NULL;

    node* htail = h2;
    while(htail->next != NULL){
        htail = htail->next;
    }
    htail->next = head;

    return h2;
}

int main(){
    node* head = takeinput();
    printer(head);
    cout<<endl;
    cout<<"Enter n"<<endl;
    int n;
    cin>>n;
    head = move_N_nodes(head,n);
    printer(head);
    return 0;
}