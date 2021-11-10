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

void swapper(node*head, int i, int j){
    node* temp = head;
    int count = 0;

    for (count = 0; count < i; count++){
        head = head->next;
    }
    
    node* p1 = head;
    node* c1 = head->next;
    count = 0;
    while(count != j){
        temp = temp->next;
        count++;
    }
    node* p2 = temp;
    node* c2 = temp->next;

    p1->next = c2;
    p2->next = c1;
    c1->next = c2->next;
    c2->next = p2;

}

int main(){
    node* head = takeinput();

    printer(head);

    swapper(head,4,8);

    printer(head);

    return 0;
}