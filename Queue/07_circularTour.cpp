#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int tour(petrolPump p [], int n){
     int deficit = 0;
     int balance = 0;
     int start = 0;
     for (int i = 0; i < n; i++)
     {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
        
     }
     if (deficit + balance >= 0)
     {
        return start;
     }
     else{
        return -1;
     }
     
     
}

int tourTest(int petrol[],int distance[], int n){
     int deficit = 0;
     int balance = 0;
     int start = 0;
     for (int i = 0; i < n; i++)
     {
        balance += petrol[i] - distance[i];
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
        
     }
     if (deficit + balance >= 0)
     {
        return start;
     }
     else{
        return -1;
     }
     
     
}
int main()
{
    int petrol[] = {6,7,4,10,6,5};
    int distance[] = {5,6,7,8,6,4};
    cout<<"Starting Point is "<<tourTest(petrol,distance,4);
    return 0;
}