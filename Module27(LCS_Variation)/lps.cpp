// Longest Palindrome Subsequence ----> LPS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a; cin>>a;
    string b = a; 
    int n = a.size();
    reverse(b.begin(), b.end());

    // performing LCS
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // printing palindrome
    int ci = n, cj = n;
    string res;
    while (ci != 0 && cj != 0)
    {
        if(a[ci-1] == b[cj-1]){
            res = a[ci-1] + res;
            ci--;
            cj--;
        }
        else if (dp[ci-1][cj] > dp[ci][cj-1]){
            ci--;
        } else {
            cj--;
        }
    }
    

    cout<<res<<endl;
    

    return 0;
}


// input -----> abcad

// input -----> mkabcdam