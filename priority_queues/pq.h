#include<vector>

using namespace std;

class priorityqueue{
    private:
    vector<int> pq;

    public:
    //we can implement an array/vector instead of a CBT
    priorityqueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }
    
    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty() == true){
            return 0;
        }
        else{
            return pq[0];
        }
    }

    void insert(int num){
        *pq.end() = num;
        
    }




};