#include<iostream>

using namespace std;

bool check_Sort(int array[],int n){
    if(n == 0 || n == 1){
        return true;
    }
    if(array[0] > array[1]){
        return false;
    }
    return check_Sort(array+1,n-1);
}

int main(){
    int arr[] = {1,2,3,4,5,6,66,7,8,9,13};
    int len = 10;

    bool ans = check_Sort(arr,len);
    
    if(ans == 1){
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }
    return 0;
}