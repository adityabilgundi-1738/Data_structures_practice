using namespace std;
template <typename T>

class node{
    public:
    node<T>* next;
    T num;

    node(T num){
        next = NULL;
        this->num = num;
    }
};

template<typename T>
class queue{
    node<T>* head;
    node<T>* tail;
    int size;

    public:

    queue(){//constructor
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T num){
        node<T>* newnode = new node<T>(num);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            // newnode = NULL;
            // delete[]newnode;
        }
        size++;
    }
    
    int getsize(){
        return size;
    }

    T front(){
        if(head == NULL){
            cout<<"Seg Fault"<<endl;
            return 0;
        }
        return head->num;
    }

    T dequeue(){
        if(head == NULL){
            cout<<"Seg Fault"<<endl;
            return 0;
        }
        T ans = head->num;
        node<T>* temp = head;
        head = NULL;
        delete[] head;
        temp = temp->next;
        head = temp;
        return ans;
    }

    bool isempty(){
        return size==0;
    }
    
};