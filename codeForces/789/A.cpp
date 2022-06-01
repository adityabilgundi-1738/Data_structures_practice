    #include<bits/stdc++.h>
    using namespace std;

    int solve(int n,vector<int> vct){
        sort(vct.begin(),vct.end());

        int zeroes = 0;

        for(auto it: vct){
            if(it == 0){
                zeroes++;
            }
        }

        if(zeroes > 0){
            return n-zeroes;
        }

        bool same = false;
        for(int i = 0; i < n - 1; i++){
            if(vct[i] == vct[i+1]){
                same = true;
            }
        }

        if(same == true) return n;
        else return n+1;
    }

    int main(){
        int t;
        cin>>t;
        for(int i = 0; i < t; i++){
            int n;
            cin>>n;
            vector<int> vct(n,0);
            for(int i = 0; i < n; i++){
                int temp;
                cin>>temp;
                vct[i] = temp;
            }
            cout<<solve(n,vct)<<endl;
        }
        return 0;
    }