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
            else{
                break;
            }
        }
    }

    void removeMin(){
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int lci,rci,pi;
        pi = 0;
        while(){
            lci = 2*pi + 1;
            rci = 2*pi + 2;
            if(rci >= pq.size()){
                int minIndex = min(lci,pi);
            }
            else if( lci >= pq.size()){
                int minIndex = min(rci,pi);
            }
            
            int minIndex = min(lci,min(rci,pi));
            if(minIndex == pi){
                break;
            }
            else{
                int temp = pq[minIndex];
                pq[minIndex] = pq[pi];
                pq[pi] = temp;
                pi = minIndex;
            } 
        }

    }
};