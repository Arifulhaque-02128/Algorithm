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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int lcs = dp[n][m];
    if(n == lcs) cout<<"YES, A is a subsequence of B"<<endl;
    else cout<<"No, A is not a subsequence of B"<<endl;
    

    return 0;
}

// input -----> AXE
// BAKXZEF