#include<iostream>

using namespace std;

int return_index(int arr[], int len ,int x){
    if(arr[0] == x){
        return 1;
    }
    else if(len == 0 && arr[0] == x){
        return 1;
    }
    else
        return 1 + return_index(arr+1,len-1, x);

}

int main(){
    int arr[] = {1,2,33,3,3,3,3,3,2,4,4,4,4,4,4,7,8,8,8,8,8,1738};
    int len = 21;
    int x;
    cin>>x;
    int index = return_index(arr,len,x);

    cout<<"Index - "<<index-1<<endl;

    return 0;
}