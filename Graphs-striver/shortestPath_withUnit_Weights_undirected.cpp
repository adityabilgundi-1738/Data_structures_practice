#include<iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

// Given an undirected graph, with unit Weights, find the shortest distance to the the node required. 

vector<int> minDist(vector<vector<int>> &adj, int n,int src){
    queue<int> q;
    vector<int> dist(n+1, INT_MAX);
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(auto it: adj[temp]){
            int tempdist = dist[temp] + 1;
            if(dist[it] > tempdist){
                q.push(it);
                dist[it] = tempdist;
            }
        }
    }
    return dist;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1, vector<int>());
    cout<<"Enter Edges"<<endl;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source;
    cout<<"Enter Source :"<<endl;
    cin>>source;

    int dest;
    cout<<"Enter Destination"<<endl;
    cin>>dest;

    vector<int> dist = minDist(adj,n,source);
    cout<<"Minimum distance from "<<source<<" to "<<dest<<" is = "<<dist[dest]<<endl;
    return 0;
}

// 9 11 1 2 2 4 1 4 2 3 3 7 4 5 5 6 6 7 7 8 8 9 7 9 -> source = 1