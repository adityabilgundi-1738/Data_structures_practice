#include<iostream>
using namespace std;

int twoptrs(int arr[], int x, int n){
    int i = 0, j = n;

    while(i < j){
        if(arr[i] + arr[j] > x){
            j--;
        }
        else if(arr[i] + arr[j] < x){
            i++;
        }
        else if(arr[i] + arr[j] == x){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 0;
}

int main(){
    int arr[]  ={10,20,30,40,50,60,70,80};
    int x;
    cout<<"Enter X"<<endl;
    cin>>x;

    int res = twoptrs(arr,x,sizeof(arr)/sizeof(arr[0]));

    if(res) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    return 0;
}