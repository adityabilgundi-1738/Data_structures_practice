#include<iostream>
#include<vector>
#include<array>

using namespace std;
int main(){
    vector<vector<int>> a;
    int n,q;
    cin>>n>>q;

    int k = 0;
    int tem;

    //taking input
    for (int i = 0; i < n; i++){
        vector<int>temp;
        cin>>k;
        for (int j = 0; j < k; j++){
            cin>>tem;
            temp.push_back(tem);
            
        }
        a.push_back(temp);
    }
    
    //printing it
    int x,y;

    for (int i = 0; i < q; i++){
        cin>>x>>y;
        cout<<a[x][y]<<endl;
        
    }
    return 0;
}


    
    
    


