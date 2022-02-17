#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<stack>

using namespace std;

// Given an directed Acyclic graph, with unit Weights, find the shortest distance to the the node required. 

stack<int> topo;

void topoSort(vector<vector<pair<int,int>>> &adj, vector<int> &vis, int n){
    vis[n] = 1;

    for(auto it: adj[n]){
        if(!vis[it.first]){
            topoSort(adj,vis,it.first);
        }
    }
    topo.push(n);
    return;
}

vector<int> minDist(vector<vector<pair<int,int>>> &adj, int n,int src){
    vector<int> dist(n+1, INT_MAX);
    int temp2 = topo.top();
    dist[temp2] = 0;

    while(!topo.empty()){
        int temp = topo.top();
        for(auto it: adj[temp]){
            if(dist[it.first] > (dist[temp] + it.second)){
                dist[it.first] = dist[temp] + it.second;
            }
        }
        topo.pop();
    }
    return dist;
}


int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
    // iterator.first = value, iterator.second = weight;
    vector<int> vis(n+1, 0);

    cout<<"Enter Edges"<<endl;

    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    int source;
    cout<<"Enter Source :"<<endl;
    cin>>source;

    int dest;
    cout<<"Enter Destination"<<endl;
    cin>>dest;

    topoSort(adj,vis,1);
    stack<int> topocopy;
    vector<int> dist = minDist(adj,n,source);

    if(INT_MAX != dist[dest]){
        cout<<"Minimum distance from "<<source<<" to "<<dest<<" is = "<<dist[dest]<<endl;
    }
    else{
        cout<<"Unreachable Node"<<endl;
    }

    return 0;
}

// 9 11 1 2 2 4 1 4 2 3 3 7 4 5 5 6 6 7 7 8 8 9 7 9 -> source = 1
// 6 7 0 1 2 0 4 1 1 2 3 2 3 6 4 2 2 4 5 4 5 3 1 -> DAG with weights (0 indexed)
// 6 7 1 2 2 1 5 1 2 3 3 3 4 6 5 3 3 5 6 4 6 4 1 -> DAG with weights (1 indexed)