#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

vector<int> topo(vector<vector<int>> &adj, vector<int> &indegree, int n){
    for (int i = 1; i <= n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int j = 1; j <= n; j++){
        if(indegree[j] == 0){
            q.push(j);
        }
    }
    vector<int> ans;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        ans.push_back(temp);

        for(auto it: adj[temp]){
            indegree[it]--;
            if(!indegree[it]){
                q.push(it);
            }
        }
    }
    return ans;
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

    vector<int> ans = topo(adj,indegree,n);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}

// 6 6 1 2 2 3 3 4 4 5 6 5 6 1
// 5 5 1 2 2 3 3 4 4 5 5 1
// 11 10 1 2 2 4 3 5 3 11 5 6 6 7 7 8 8 9 9 10 10 5 -> cyclic directed

// Okay so to clarify the (cnt == N) logic.

// In Kahn's algorithm, a node only enters the queue if its indegree becomes zero and then it further decrements the indegree values of its adjacent nodes right. 
// But in the case of cyclic graph , there will be a node from where the cycle will be starting and then coming to an end. 
// So in order for the elements present in the cycle to get pushed into the queue, that cycle starting node's indegree must become zero right. 
// But but but, that node's indegree will never become zero as one of the node from the cycle (the second last element) will be pointing towards the starting node. 
// Just imagine with a diagram in the video. So if that node's indegree will never become zero , 
// then it will restrict its adjacent nodes(at least) to get evaluated and hence the total number of nodes getting pushed into the queue (cnt) will never become (=N).
