#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subsetSum(int n, int arr[], int s){
    if(n == 0){
        if(s == 0) return 1;
        else return 0;
    }

    if(dp[n][s] != -1) return dp[n][s];

    if(arr[n-1] <= s){
        int choice1 = subsetSum(n-1, arr, s-arr[n-1]);
        int choice2 = subsetSum(n-1, arr, s);

        dp[n][s] = choice1 + choice2;

        return dp[n][s];
    }

    else {
        dp[n][s] = subsetSum(n-1, arr, s);
        return dp[n][s];
    }
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int s; cin>>s;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = -1;
        }
    }

    int res = subsetSum(n, arr, s);

    cout<<res<<endl;
    
    return 0;
}



// input ----> 4
// 1 2 4 6
// 7