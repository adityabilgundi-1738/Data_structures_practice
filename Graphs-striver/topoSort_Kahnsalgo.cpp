#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// This only works on DAC i.e -> Directed Acyclic Graph

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

    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 6 5 6 1
// 5 5 1 2 2 3 3 4 4 5 5 1

// 11 10 1 2 2 4 3 5 3 11 5 6 6 7 7 8 8 9 9 10 10 5 -> cyclic directed
// 11 10 1 2 2 4 3 5 5 6 6 7 5 8 8 9 9 10 10 7 10 11 -> cyclic non - directed