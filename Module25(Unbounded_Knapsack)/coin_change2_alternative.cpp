#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7+5;

int main()
{
    int n; cin>>n;
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    int s; cin>>s;
    int dp[n+1][s+1];
    dp[0][0] = 0;
    for (int i = 1; i <= s; i++) dp[0][i] = INF;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(w[i-1] <= j) {
                int choice1 = dp[i][j-w[i-1]] + 1;
                int choice2 = dp[i-1][j];
                dp[i][j] = min(choice1, choice2);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if(dp[i][j] < INF) cout<<dp[i][j]<<" ";
            else cout<<"x ";
            
        }
        cout<<endl;
    }
    
    cout<<dp[n][s]<<endl;
    
    return 0;
}

// // input -----> 3
// 1 2 3
// 5

// input ----> 2
// 2 3
// 6