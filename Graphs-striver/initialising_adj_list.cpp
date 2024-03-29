#include <iostream>
#include<vector>
using namespace std;

// matrix

// int main(){
//     int n,m;
//     cin>>n>>m;
//     int adj[n+1][n+1];

//     for (int i = 0; i < m; i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
//     return 0;
// }

// This uses a space complexity of n^2
// so inorder to decrease this, we use an adjancecy list.

int main(){
    int n,m;
    // n nodes and m edges
    cin>>n>>m;
    vector<int> adj[n+1]; 
    // assuming that this is a 1-based graph index

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // push back u to v and v to u if it is an undirected graph else only u to v
    }
    return 0;
}
// 6 6 1 2 2 3 3 4 4 5 5 6 6 1

// if the edges have weights, then we create a vector of pairs.
// we will store the pair as <int, int> where <adj node, weight>
// adj[u].push_back({v,w})