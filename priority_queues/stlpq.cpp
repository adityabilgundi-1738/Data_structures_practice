#include<queue>
#include<iostream>

using namespace std;

int main(){
    // priority_queue<int> pq; -> Min heap
    // priority_queue<int, vector<int>, greater<int>> pq; -> Max Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(4);
    pq.push(2);

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}