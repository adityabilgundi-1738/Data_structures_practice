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

node* evenafterodd(node* head){
    node* oddhead = NULL;
    node* oddtail = NULL;
    node* evenhead = NULL;
    node* eventail = NULL;

    node*temp = head;

    while(temp != NULL){
        
        if((temp->num)%2 == 0){//even
            if(evenhead == NULL){
                evenhead = temp;
                eventail = temp;
            }
            else{
                eventail->next = temp;
                eventail = temp;
            }
        }
        
        else{
            if(oddhead == NULL){
                oddhead = temp;
                oddtail = temp;
            }
            else{
                oddtail->next = temp;
                oddtail = temp;
            }
        }
        
        temp = temp->next;
    }
    //we have two sorted linked lists

    head = oddhead;
    oddtail->next = evenhead;
    eventail->next = NULL;

    return head;
}

int main(){

    node* head = takeinput();
    cout<<"Before"<<endl;
    printer(head);
    cout<<endl;

    head = evenafterodd(head);
    cout<<"after"<<endl;
    printer(head);

    return 0;
}