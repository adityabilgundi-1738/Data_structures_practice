#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int j = 0; j < t; j++)
    {
        int arr1[3], arr2[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> arr2[i];
        }
        if ((arr1[0] + arr1[1] + arr1[2]) > (arr2[0] + arr2[1] + arr2[2]))
        {
            cout << "Dragon" << endl;
        }
        else if ((arr1[0] + arr1[1] + arr1[2]) < (arr2[0] + arr2[1] + arr2[2]))
        {
            cout << "Sloth" << endl;
        }
        else if (arr1[0] > arr2[0])
        {
            cout << "Dragon" << endl;
        }
        else if (arr1[0] < arr2[0])
        {
            cout << "Sloth" << endl;
        }
        else if (arr1[1] > arr2[1])
        {
            cout << "Dragon" << endl;
        }
        else if (arr1[1] < arr2[1])
        {
            cout << "Sloth" << endl;
        }
        else if (arr1[2] > arr2[2])
        {
            cout << "Dragon" << endl;
        }
        else if (arr1[2] < arr2[2])
        {
            cout << "Sloth" << endl;
        }
        else
        {
            cout << "tie" << endl;
        }
    }

    return 0;
}