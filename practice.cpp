#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][3], int target)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}


int rowSum(int arr[][3]){
    int maxi = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum = sum + arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
        }
    }
    return maxi;

    
}


void colSum(int arr[][3]){
    for (int j = 0; j < 3; j++)
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum = sum + arr[i][j];
        }
        cout<<sum<<" ";
    }
    
}

int main()
{
    // input
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // output
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    if (isPresent(arr, 15))
    {
        cout << "Element is Found" << endl;
    }
    else
    {
        cout << "No Element is Found" << endl;
    }
    cout<<endl;
    cout<<rowSum(arr);
    cout<<endl;
    colSum(arr);
    return 0;
}