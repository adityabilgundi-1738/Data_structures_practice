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

node* reverse(node* head){//reverses
    node* current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

bool check_pali(node* head){
    node* h1 = head;
    node* h2 = midpoint(head);
    h2 = reverse(h2);

    //comparing
    bool ans;
    while(h1 != NULL || h2 != NULL){
        if(h1->num == h2->num){
            ans = true;
        }
        else{
            cout<<"Not a Palindrome"<<endl;
            ans = false;
            break;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return ans;
}

int main(){
    node* head = takeinput();
    printer(head);
    cout<<endl;

    bool ans = check_pali(head);
    
    if(ans == true){
        cout<<"Yes it is a Palindrome"<<endl;
    }

    return 0;
}