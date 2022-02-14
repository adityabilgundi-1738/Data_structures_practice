#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vis(1000, 0);
vector<vector<int>> adjmatrix(1000, vector<int>());

void dfs(int v){
    vis[v] = 1;
    cout << v << " ";

    vector<int>::iterator it;
    for (auto &it : adjmatrix[v])
    {
        if(!vis[it])
        dfs(it);
    }
}

void takeinput(){
    cout << "Enter the number of nodes and edges" << endl;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjmatrix[u].push_back(v);
        adjmatrix[v].push_back(u);
    }
    cout << "Input Taken!" << endl;
}

int main(){
    takeinput();
    cout << "Enter the vertex from where you require the dfs" << endl;
    int v;
    cin >> v;
    dfs(v);

    return 0;
}