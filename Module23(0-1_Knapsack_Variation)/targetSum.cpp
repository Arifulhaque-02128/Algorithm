#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }

    int target; cin>>target;
    int s = (target + sum)/2;

    int dp[n+1][s+1];
    dp[0][0] = 1;
    
    for(int i=1; i<=s; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(arr[i-1] <= j) {
                int choice1 = dp[i-1][j-arr[i-1]];
                int choice2 = dp[i-1][j];
                dp[i][j] = choice1 + choice2;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<"Target Sum is possible in "<<dp[n][s]<<" way."<<endl;

    
    return 0;
}


// input ----> 4
// 1 1 2 3
// 1