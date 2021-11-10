#include<iostream>

// using namespace std;

// Polluting 'using namespace std;' everywhere ;=;

class node{
    public:
    node* next;
    int num;

    node(int num){
        next = NULL;
        this->num = num;
    }
};

class pair{
    public:
    node* head;
    node* tail;
};

pair reversal_2(node* head){
    if(head == NULL || head->next == NULL){
        pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    pair temp = reversal_2(head->next);
    temp.tail->next = head;
    head->next = NULL;
    temp.tail = temp.tail->next;

    pair ans;
    ans.head = temp.head;
    ans.tail = temp.tail;

    return ans;
}

node* reversal_better(node* head){
    return reversal_2(head).head;
}

node* takeinput(){
    int num;
    std::cin>>num;

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
        std::cin>>num;
    }

    return head;
}

void printer(node* head){
    while(head != NULL){
        std::cout<<head->num<<" ";
        head = head->next;
    }
}

int main(){
    node* head = takeinput();
    printer(head);
    std::cout<<std::endl;
    head = reversal_better(head);
    printer(head);
    std::cout<<std::endl;

    return 0;
}