#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Dfs for a Directed Graph produces a tree.

bool dfsHelper(int i, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &adj){
    vis[i] = 1;
    dfsVis[i] = 1;

    for(auto it: adj[i]){
        if(!vis[it]){
            if(dfsHelper(it,vis,dfsVis,adj)){
                return true;
            }
        }
        else if(dfsVis[it]){
            return true;
        }
    }
    dfsVis[i] = 0;
    return false;
}

bool checkCyclic(vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfsVis, int n){
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfsHelper(i, vis, dfsVis, adj)){
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
    vector<int> vis(n+1, 0);
    vector<int> dfsVis(n+1, 0);

    cout<<"Enter the edge values"<<endl;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(checkCyclic(adj,vis,dfsVis,n)){
        cout<<"It is a Cyclic Graph"<<endl;
    }
    else{
        cout<<"It is not a Cyclic Graph"<<endl;
    }
    
    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 5 6 6 1 -> bip
// 5 5 1 2 2 3 3 4 4 5 5 1 -> non bip

// 11 10 1 2 2 4 3 5 3 11 5 6 6 7 7 8 8 9 9 10 10 5 -> cyclic directed
// 11 10 1 2 2 4 3 5 5 6 6 7 5 8 8 9 9 10 10 7 10 11 -> cyclic non - directed