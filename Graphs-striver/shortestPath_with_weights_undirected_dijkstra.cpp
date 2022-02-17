#include<iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

// Given an undirected graph, with Weights, find the shortest distance to the the node required. 

void dijkstra(vector<vector<pair<int,int>>> &adj, vector<int> &dist, int n){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[n] = 0;
    pq.push({0,n});

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        for(auto it: adj[temp.second]){
            int tempdist = temp.first + it.second;
            if(tempdist < dist[it.first]){
                pq.push({tempdist,it.first});
                dist[it.first] = tempdist;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
    // iterator.first = value, iterator.second = weight;
    vector<int> dist(n+1, INT_MAX);

    cout<<"Enter Edges"<<endl;

    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int source;
    cout<<"Enter Source:"<<endl;
    cin>>source;

    dijkstra(adj,dist,source);
    
    // int dest;
    // cout<<"Enter Destination:"<<endl;
    // cin>>dest;
    // cout<<"Minimum distance from "<<source<<" to "<<dest<<" is = "<<dist[dest]<<endl;

    cout<<"Printing all distances"<<endl;
    for (int i = 1; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}

// 9 11 1 2 2 4 1 4 2 3 3 7 4 5 5 6 6 7 7 8 8 9 7 9 -> source = 1
// 6 7 0 1 2 0 4 1 1 2 3 2 3 6 4 2 2 4 5 4 5 3 1 -> DAG with weights (0 indexed)
// 6 7 1 2 2 1 5 1 2 3 3 3 4 6 5 3 3 5 6 4 6 4 1 -> DAG with weights (1 indexed)
// 5 6 1 2 2 1 4 1 4 3 3 3 5 1 2 3 4 2 5 5 -> undirected with weights