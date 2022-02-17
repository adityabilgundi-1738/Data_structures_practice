#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// As Kahns algo is only applicable for DAC if we get a topo sort then it is Acyclic. but if we dont then it is cyclic

bool topo(vector<vector<int>> &adj, vector<int> &indegree, int n){
    for (int i = 1; i <= n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    int count = 0;

    for (int j = 1; j <= n; j++){
        if(indegree[j] == 0){
            q.push(j);
        }
    }

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        count++;

        for(auto it: adj[temp]){
            indegree[it]--;
            if(!indegree[it]){
                q.push(it);
            }
        }
    }
    if(count == n) return true;
    else return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> indegree(n+1, 0);

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(topo(adj,indegree,n)) cout<<"Acyclic"<<endl;
    else cout<<"Cyclic"<<endl;

    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 6 5 6 1
// 5 5 1 2 2 3 3 4 4 5 5 1

// 11 10 1 2 2 4 3 5 3 11 5 6 6 7 7 8 8 9 9 10 10 5 -> cyclic directed
// 11 10 1 2 2 4 3 5 5 6 6 7 5 8 8 9 9 10 10 7 10 11 -> cyclic non - directed