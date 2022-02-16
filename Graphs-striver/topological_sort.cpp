#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// This only works on DAC i.e -> Directed Acyclic Graph

stack<int> topo;

void topoHelper(vector<vector<int>> &adj, vector<int> &vis, int i){
    vis[i] = 1;

    for(auto it: adj[i]){
        if(!vis[it]){
            topoHelper(adj,vis,it);
        }
    }
    topo.push(i);
    return;
}

void topoSort(vector<vector<int>> &adj, vector<int> &vis, int n){
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            topoHelper(adj,vis,i);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> vis(n+1, 0);


    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    
    topoSort(adj,vis,n);
    int nasd = topo.size();

    for (int i = 0; i < nasd; i++){
        cout<<topo.top()<<endl;
        topo.pop();
    }
    

    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 6 5 6 1
// 5 5 1 2 2 3 3 4 4 5 5 1

// 11 10 1 2 2 4 3 5 3 11 5 6 6 7 7 8 8 9 9 10 10 5 -> cyclic directed
// 11 10 1 2 2 4 3 5 5 6 6 7 5 8 8 9 9 10 10 7 10 11 -> cyclic non - directed