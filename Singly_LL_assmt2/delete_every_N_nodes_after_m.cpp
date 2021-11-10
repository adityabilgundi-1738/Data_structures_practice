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

void deleteNafterM(node* head,int m, int n){
    node* temp1 = head;
    node* temp2 = NULL;
    int count = 1;

    while(temp1 != NULL){
        while ((count < m) && (temp1 != NULL)){//skipping loop 
            temp1 = temp1->next;
            count++;
        }
        
        if(temp1 == NULL){
            return;
        }

        temp2 = temp1->next;

        while ((count <= n) && (temp2 != NULL)){//free() loop
            node* temp3 = temp2;
            temp2 = temp2->next;
            free(temp3);
            count++;
        }
        
        temp1->next = temp2;
        temp1 = temp2;
    }

}

int main(){

    node* head = takeinput();
    printer(head);
    cout<<endl;
    int m,n;
    cout<<"Enter M & N"<<endl;
    cin>>m;
    cin>>n;

    deleteNafterM(head,m,n);
    printer(head);

    return 0;
}