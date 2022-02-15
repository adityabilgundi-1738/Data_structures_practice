#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// given two colors and a graph, if we paint evenry node,
// None of the two adjacent nodes can have the same colours.

bool dfs(int i, int parent, vector<vector<int>> &adj, vector<int> &coloured){
    if(coloured[i] == -1){
        coloured[i] = 0;
    }
    for(auto it: adj[i]){
        if(coloured[it] == -1){
            coloured[it] = !coloured[i];
            if(!dfs(it, i, adj, coloured)) return false;
        }
        else if(coloured[it] == coloured[i]){
            return false;
        }
    }
    return true;
}

bool checkBipartite_dfs(int n, vector<vector<int>> &adj, vector<int> &coloured){
    for (int i = 1; i <= n; i++){
        if(coloured[i] == -1){
            if(!dfs(i,-1 ,adj,coloured)) return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> coloured(n+1, -1);

    cout<<"Enter the edge values"<<endl;

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = checkBipartite_dfs(n, adj, coloured);

    if(ans){
        cout<<"It is a Bipartite Graph"<<endl;
    }
    else{
        cout<<"It is not a Bipartite Graph"<<endl;
    }
    
    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 5 6 6 1 -> bip
// 5 5 1 2 2 3 3 4 4 5 5 1 -> non bip