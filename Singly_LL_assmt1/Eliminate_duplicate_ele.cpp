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

node* unique_maker(node* head){
    
    if(head == NULL || head->next == NULL){
        cout<<"LL is too Short"<<endl;
        return head;
    }

    node* t1 = head;
    node* t2 = head->next;

    while(t2 != NULL){        
        if(t1->num != t2->num){
            t1= t2;
            t2 = t2->next;
        }
        
        else if(t1->num == t2->num){
            node* temp = t2;
            t2 = t2->next;
            t1->next = t2;
            delete(temp);
        }
        else
        continue;
    }
    t1->next = NULL;
    return head;
}

int main(){
    node* head = takeinput();
    cout<<"Before"<<endl;
    printer(head);
    cout<<endl;

    head = unique_maker(head);
    cout<<"After"<<endl;
    printer(head);
    cout<<endl;
    
    return 0;
}