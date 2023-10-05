#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    for (int k = 0; k < t; k++)
    {
        int n, m; cin>>n>>m;
        int s = 1000 - m;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        bool dp[n+1][s+1];
        dp[0][0] = true;
        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if(arr[i-1] <= j) {
                    bool choice1 = dp[i-1][j-arr[i-1]];
                    bool choice2 = dp[i-1][j];
                    dp[i][j] = choice1 || choice2;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[n][s]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
    return 0;
}



// input -----> 3
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 6 900
// 10 20 30 40 50 60