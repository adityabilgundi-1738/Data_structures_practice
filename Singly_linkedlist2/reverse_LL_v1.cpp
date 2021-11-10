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

node* merger(node* h1, node* h2){
    node* fhead = NULL;
    node* ftail = NULL;

    while(h1 != NULL && h2 != NULL){
        if(fhead == NULL){
            fhead = (h1->num < h2->num) ? h1 : h2;
            ftail = fhead;
            if(h1->num < h2->num){
                h1 = h1->next;
            }
            else
                h2 = h2->next;
        }
        else{
            ftail->next = (h1->num < h2->num) ? h1 : h2;
            ftail = ftail->next;
            if(h1->num < h2->num){
                h1 = h1->next;
            }
            else
                h2 = h2->next;
        }
    }
    if(h1 == NULL){
        ftail->next = h2;
        return fhead;
    }
    else if(h2 == NULL){
        ftail->next = h1;
        return fhead;
    }
    else
    return fhead;
}

int length(node* head){
    int count = 1;
    while(head->next != NULL){
        count++;
        head = head->next;
    }
    return count;
}

node* reversal(node* head){//n^2 complexity
    //base case
    //if length is 1 then it is already reversed
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* temp = reversal(head->next);
    node* temp2 = temp;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = head;
    head->next = NULL;
    return temp;
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
