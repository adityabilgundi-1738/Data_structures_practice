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

node* mergesort(node* head){
    //base case
    if(head->next == NULL){
        return head;
    }
    
    //making two parts of the LL
    node* head1 = head;
    node* mid = midpoint(head1);
    node* head2 = mid->next;
    mid->next = NULL;
    //recursion call
    node* finalhead = merger(mergesort(head1),mergesort(head2));  

    return finalhead;
}

int main(){
    node* head = takeinput();
    printer(head);
    cout<<endl;
    head = mergesort(head);
    printer(head);

    return 0;
}