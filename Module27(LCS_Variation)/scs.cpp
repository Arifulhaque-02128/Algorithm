// shortest common superstring ----> SCS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a, b; cin>>a>>b;
    int n = a.size();
    int m = b.size();

    int dp[n+1][m+1];
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

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
    
    int res = (n+m) - dp[n][m];
    cout<<res<<endl;

    // print smallest common superstring
    string seq;
    int ci = n; 
    int cj = m;

    while(ci != 0 && cj != 0){
        if(a[ci-1] == b[cj-1]){
            seq = a[ci-1] + seq;
            ci--;
            cj--;
        }
        else if (dp[ci-1][cj] > dp[ci][cj-1]){
            seq = a[ci-1] + seq;
            ci--;
        } else {
            seq = b[cj-1] + seq;
            cj--;
        }
    }

    while (ci != 0)
    {
        seq = a[ci-1] + seq;
        ci--;
    }
    
    while (cj != 0)
    {
        seq = b[cj-1] + seq;
        cj--;
    }

    cout<<seq<<endl;
    
    
    return 0;
}


// input ----> peek
// eke


// input ----> CKKGCD
// KXGXCYD