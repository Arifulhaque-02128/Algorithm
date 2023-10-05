#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int fibo_series[n];
    fibo_series[0] = 1;
    fibo_series[1] = 1;
    for (int i = 2; i < n; i++)
    {
        fibo_series[i] = fibo_series[i-1] + fibo_series[i-2];
    }

    for(int f:fibo_series){
        cout<<f<<" ";
    }
    
    return 0;
}