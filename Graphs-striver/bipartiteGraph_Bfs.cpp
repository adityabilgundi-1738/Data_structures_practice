#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// given two colors and a graph, if we paint evenry node,
// None of the two adjacent nodes can have the same colours.

bool helper(int i, vector<vector<int>> &adj, vector<int> &coloured){
    queue<int> q; //nodevalue, parent
    q.push(i);
    coloured[i] = 0;
    
    while(!q.empty()){
        int temp = q.front(); 
        q.pop();

        for(auto it: adj[temp]){
            if(coloured[it] == -1){
                coloured[it] = !coloured[temp];
                q.push(it);
            }
            else if(coloured[it] == coloured[temp]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite_bfs(int n, vector<vector<int>> &adj, vector<int> &coloured){
    for (int i = 1; i <= n; i++){
        if(coloured[i] == -1){
            if(helper(i,adj,coloured)) return true;
        }
    }
    return false;
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

    bool ans = checkBipartite_bfs(n, adj, coloured);

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