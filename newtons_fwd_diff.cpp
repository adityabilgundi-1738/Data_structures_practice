#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int factorial(int n){
    int res = 1;
    for (int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}

int main(){
    cout<<"Newton's Forward Difference Method"<<endl;

    cout<<"Enter No.Of given X values"<<endl;
    int n;
    cin>>n;
    vector<vector<float>> differenceTable(n,vector<float> (n+1));

    cout<<"Enter the X values"<<endl;
    for (int i = 0; i < n; i++){
        float val;
        cin>>val;
        differenceTable[i][0] = val;
    }

    cout<<"Enter the f(x) values for the respective X values"<<endl;
    for (int i = 0; i < n; i++){
        cout<<"enter f(x) for x - "<<differenceTable[i][0]<<" = "<<endl;
        float val;
        cin>>val;
        differenceTable[i][1] = val;
    }

    //now we have a two columned table with x and f(x)

    for (int i = 2; i <= n; i++){
        for (int j = 0; j < n - i + 1; j++)
            differenceTable[j][i] = differenceTable[j + 1][i - 1] - differenceTable[j][i - 1];
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i + 1; j++)
            cout<<setw(4)<<differenceTable[i][j]<<"\t";
        cout<<endl;
    }

    double reqX;
    cout<<"Enter the X value for which f(x) value is to be interpolated = ";
    cin>>reqX;

    double h = abs(differenceTable[0][0] - differenceTable[1][0]);
    double u = (reqX - differenceTable[0][0])/h;
    double reqY;

    double term = u*differenceTable[0][2];
    double sum = term;

    for (int i = 2; i <= n + 2; i++){
        term *= (u-i+1);
        term *= differenceTable[0][i+1]/differenceTable[0][i];
        term *= factorial(i-1)/factorial(i);
        sum += term;
    }
    sum += differenceTable[0][1];
    // cout<<u<<endl;
    // cout<<h<<endl;
    cout<<sum<<endl;
    
    //7 1 2 3 4 5 6 7 14 21 32 41 56 58 74 3.5
}