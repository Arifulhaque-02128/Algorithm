#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, s; cin>>n>>s;
    int val[n];
    int w[n];
    for (int i = 0; i < n; i++) cin>>val[i];
    for (int i = 0; i < n; i++) cin>>w[i];

    int dp[n+1][s+1];
    for (int i = 0; i <= s; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if(w[i-1] <= j){
                int choice1 = dp[i][j-w[i-1]] + val[i-1];
                int choice2 = dp[i-1][j];
                dp[i][j] = max(choice1, choice2);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Maximum value - "<<dp[n][s]<<endl;
    
    
    return 0;
}