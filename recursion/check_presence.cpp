#include<iostream>

using namespace std;

bool check_pres(int array[],int num,int len){
    if(len != 0){
        if(array[0] == num){
            return true;
        }
        else
        return check_pres(array+1,num,--len);
    }
    else
        return false;
}

int main(){
    int arr[] = {1,2,3,4,77,88,99,1001};
    int len = 8;
    cout<<"Enter the number needed to check"<<endl;
    int num;
    cin>>num;
    bool ans = check_pres(arr,num,len);
    
    if(ans == 1){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
    return 0;
}