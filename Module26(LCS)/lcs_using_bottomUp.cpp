#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b; cin>>a>>b;
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                int choice1 = dp[i-1][j];
                int choice2 = dp[i][j-1];
                dp[i][j] = max(choice1, choice2);
            }
        }
    }

    cout<<dp[n][m]<<endl;
    
    
    return 0;
}


// input -----> abd
// bed