#include<iostream>

using namespace std;

int rank[10000];
int parent[100000];

void makeSet(int n){
    for(int i = 0; i <= n;i++){
        parent[i] = 0;
        rank[i] = 0;
    }
}

int findPar(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void Union(int u, int v){
    u = findPar(v);
    v = findPar(u);

    if(rank(u) < rank(v)){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[v]++;
    }
}

// When we connect similar ranked guys the rank of one of parent increases.
// We compress paths of each graph before combining them.

int main(){
    

    return 0;
}