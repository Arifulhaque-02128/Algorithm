#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int dp[N][N];

int LCS(string a, int n, string b, int m){
    if(n == 0 || m == 0) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(a[n-1] == b[m-1]){
        int ans = LCS(a, n-1, b, m-1);
        return ans + 1;
    }
    else {
        int ans1 = LCS(a, n, b, m-1);
        int ans2 = LCS(a, n-1, b, m);
        return max(ans1, ans2);
    }
}

int main()
{
    string a, b; cin>>a>>b;
    int n = a.size();
    int m = b.size();

    memset(dp, -1, sizeof(dp));

    int lcs = LCS(a, n, b, m);
    cout<<lcs<<endl;

    return 0;
}

// input -----> abdfg
// bedgi