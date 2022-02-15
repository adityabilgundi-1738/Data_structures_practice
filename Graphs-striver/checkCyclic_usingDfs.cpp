#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Given an undirected graph, how to check if there is a cycle in the graph?

bool dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj){
    // for (int j = 0; j < adj[node].size(); j++){
    //     if(!vis[adj[node][j]]){
    //         if(recDfs(adj[node][j], node, vis, adj)){
    //             return true;
    //         }
    //     }
    //     else if(vis[adj[node][j]] != parent){
    //         return true;
    //     }
    // }
    
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, node, vis, adj)) return true;   
        }
        else if(it != parent) return true;
    }
    return false;
}

bool cycleChecker(vector<vector<int>> &adj, int n, vector<int> &vis){
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i, -1, vis, adj)){
                return true;
            }
        }
    }
    return false;
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

    vector<int> vis(n+1,0);

    bool ans = cycleChecker(adj,n,vis);
    if(ans){
        cout<<"The Graph is Cyclic"<<endl;
    }
    else{
        cout<<"The Graph is nonCyclic"<<endl;
    }
    return 0;
}