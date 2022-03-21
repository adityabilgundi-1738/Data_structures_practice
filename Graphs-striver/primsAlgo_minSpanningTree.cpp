#include<iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

// Given an undirected graph, with Weights, find the shortest distance to the the node required. 

// void dijkstra(vector<vector<pair<int,int>>> &adj, vector<int> &dist, int n){
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//     dist[n] = 0;
//     pq.push({0,n});

//     while(!pq.empty()){
//         pair<int,int> temp = pq.top();
//         pq.pop();
//         for(auto it: adj[temp.second]){
//             int tempdist = temp.first + it.second;
//             if(tempdist < dist[it.first]){
//                 pq.push({tempdist,it.first});
//                 dist[it.first] = tempdist;
//             }
//         }
//     }
// }

void mstPrims(vector<vector<pair<int,int>>> &adj, vector<int> &dist, vector<bool> &mst, vector<int> &parent, int n){
    dist[1] = 0;
    mst[1] = true;
    parent[1] = -1;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    for(int count = 1; count <= n; count++){
        int u = pq.top().second;
        pq.pop();
        mst[u] = true;

        for (auto it: adj[u]){
            if(it.second < dist[it.first] && mst[it.first] == false){
                parent[it.first] = u;
                pq.push({dist[it.first], it.first});
                dist[it.first] = it.second;
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
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);
    
    for (int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    mstPrims(adj,dist,mst,parent,n);
    cout<<endl;
    cout<<"Generating Minimum spanning Tree"<<endl;
    cout<<"Printing all edges of the MST"<<endl;
    for (int i = 2; i <= n; i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return 0;
}

// 9 11 1 2 2 4 1 4 2 3 3 7 4 5 5 6 6 7 7 8 8 9 7 9 -> source = 1
// 6 7 0 1 2 0 4 1 1 2 3 2 3 6 4 2 2 4 5 4 5 3 1 -> DAG with weights (0 indexed)
// 6 7 1 2 2 1 5 1 2 3 3 3 4 6 5 3 3 5 6 4 6 4 1 -> DAG with weights (1 indexed)
// 5 6 1 2 2 1 4 1 4 3 3 3 5 1 2 3 4 2 5 5 -> undirected with weights