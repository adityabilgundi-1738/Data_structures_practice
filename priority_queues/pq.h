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
        pq.push_back(num);
        int childindex = pq.size() -1;

        while(childindex > 0){
            int parentIndex = (childindex -1)/2;

            if(pq[childindex] < pq[parentIndex]){
                int temp;
                temp = pq[childindex];
                pq[childindex] = pq[parentIndex];
                pq[parentIndex] = temp;
                childindex = parentIndex;
            }
        }
    }




};