#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Given an undirected graph, how to check if there is a cycle in the graph?

bool cycleBfsChecker(int i, vector<vector<int>> &adj, int n, vector<int> &vis){
    queue<pair<int,int>> q;
    q.push({i,-1});
    vis[i] = 1;

    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        
        for(auto it : adj[temp.first]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it,temp.first});
            }
            else if(temp.second != it){
                return true;
            }
        }
    }
    return false;
}

bool cycleChecker(vector<vector<int>> &adj, int n, vector<int> &vis){
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            if(cycleBfsChecker(i, adj, n, vis)){
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