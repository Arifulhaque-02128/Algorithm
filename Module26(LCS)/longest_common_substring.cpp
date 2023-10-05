#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b; cin>>a>>b;
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];
    for(int i=0; i<=m; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = 0;

    int maxLen = 0;
    int ci = 0, cj = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(maxLen <= dp[i][j]){
                    maxLen = dp[i][j];
                    ci = i;
                    cj = j;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    
    // cout<<dp[ci][cj]<<endl;
    cout<<maxLen<<endl;

    string str;
    while (ci != 0 && cj != 0)
    {
        if(a[ci-1] == b[cj-1]){
            str = a[ci-1] + str;
            ci--;
            cj--;
        } else {
            break;
        }
    }

    cout<<str<<endl;
    
    return 0;
}

// input -----> aceghr
// acaeghbr