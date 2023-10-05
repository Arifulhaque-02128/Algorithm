// https://www.spoj.com/problems/FARIDA/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;

    for (int m = 1; m <= t; m++)
    {
        int n; cin>>n;
        long long arr[n];
        long long memo[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            memo[i] = arr[i];
        }

        if(n == 0) cout<<"Case "<<m<<": "<<0<<endl;
        else if(n == 1) cout<<"Case "<<m<<": "<<arr[n-1]<<endl;
        else if(n == 2) cout<<"Case "<<m<<": "<<max(arr[n-1], arr[n-2])<<endl; 

        else {
            memo[1] = max(memo[0], memo[1]);

            for (int i = 2; i < n; i++)
            {
                memo[i] = max(memo[i-1], memo[i-2]+arr[i]);
            }

            cout<<"Case "<<m<<": "<<memo[n-1]<<endl;
        }
        
    }
    
    return 0;
}