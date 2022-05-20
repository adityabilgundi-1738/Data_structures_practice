#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m){
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    cin >> a[i][j];
        }
	}

    vector<int> columns;
    for(int i = 0; i < n && columns.empty(); i++){
        vector<int> sorted = a[i];
        sort(sorted.begin(), sorted.end());
        for(int k = 0; k < m; k++){
            if(a[i][k] != sorted[k]) columns.push_back(k);
        }
    }

    if((int)columns.size() == 0){
        cout<<"1 1"<<endl;
        return;
    }
    if((int)columns.size() > 2){
        cout<<"-1"<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        swap(a[i][columns[0]], a[i][columns[1]]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m;j++){
            if(a[i][j] < a[i][j-1]){
                cout<<"-1"<<endl;
                return;
            }
        }
    }

    cout<<columns[0]+1<<" "<<columns[1]+1<<endl;
    return;
}

int main(){
    int cases;
    cin>>cases;
    for(int i = 0; i < cases; i++){
        int n,m;
        cin>>n>>m;
        solve(n,m);
    }
    return 0;
}