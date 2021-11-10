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

int main(){
    cout<<"Enter first sorted LL"<<endl;
    node* head1 = takeinput();
    printer(head1);
    cout<<endl;

    cout<<"Enter second sorted LL"<<endl;
    node* head2 = takeinput();
    printer(head2);
    cout<<endl;

    cout<<"Merged LL"<<endl;
    node* merged = merger(head1,head2);
    printer(merged);
    cout<<endl;

    return 0;
}