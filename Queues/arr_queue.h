using namespace std;
template <typename T>

class queue{
    T* data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

    public:
    
    queue(int s){//def constructor
        data = new T[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;

    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size == 0;
    }

    void enqueue(T element){
        if(size == capacity){
            T* newdata = new T[capacity*2];
            int j = 0;
            for (int i = firstindex; i < capacity; i++){
                newdata[j] = data[i];
                j++;
            }
            for(int i = 0; i<firstindex; i++){
                newdata[j] = data[i];
                j++;
            }
            delete[]data;
            data = newdata;
            firstindex = 0;
            nextindex = capacity;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;//circular if I reach the end of the array
        if(firstindex == -1){
            firstindex = 0;
        }
        size++;
    }
    
    T front(){
        if(isempty()){
            cout<<"Queue Empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }

    T dequeue(){
        if(isempty()){
            cout<<"Queue Empty"<<endl;
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex + 1) % capacity;//circular if I reach the end of the array
        size--;
        if(size == 0){//resetting queue if size = 0
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }

};  